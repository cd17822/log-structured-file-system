#include "commands.cpp"

void parseLine(std::string line) {
  if (line.length() == 0) return;

  std::vector<std::string> command = split(line);

  if      (command[0] == "import"    && command.size() == 3) import(command[1], command[2]);
  else if (command[0] == "remove"    && command.size() == 2) remove(command[1]);
  else if (command[0] == "cat"       && command.size() == 2) cat(command[1]);
  else if (command[0] == "display"   && command.size() == 4) display(command[1], command[2], command[3]);
  else if (command[0] == "overwrite" && command.size() == 5) overwrite(command[1], command[2], command[3], command[4]);
  else if (command[0] == "list"      && command.size() == 1) list();
  else if (command[0] == "exit"      && command.size() == 1) exit();
  else std::cout << "Command not recognized." << std::endl;
}

int main(int argc, char* argv[]){
  struct stat st = {0};

  if (stat("./DRIVE", &st) == -1){
    std::cout << "Could not find DRIVE. Please run 'make drive' and try again." << std::endl;
    return 1;
  }

  std::string line;

  std::cout << "LFS$ ";
  while (getline(std::cin, line)){
    parseLine(line);
    std::cout << "LFS$ ";
  }

  return 0;
}
