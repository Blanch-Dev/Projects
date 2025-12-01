#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Task {
public:
  std::string name;
  std::string description;
  Task(std::string name, std::string description) {
    this->name = name;
    this->description = description;
  }

private:
};

class WriteFile {
public:
private:
};

std::vector<Task> tasks;

int menu() {
  std::cout << "================== MENU ==================" << std::endl;
  std::cout << "1 - New Task" << std::endl;
  std::cout << "2 - Delete Task" << std::endl;
  std::cout << "3 - Show Tasks" << std::endl;
  std::cout << "X - Close" << std::endl << std::endl;
  int option;
  std::cout << "OPTION: ";
  std::cin >> option;
  std::cout << std::endl;
  return option;
}

int addTask() {
  std::string name, description;
  std::cout << "Name: ";
  // ERROR
  std::getline(std::cin, name);
  std::cout << "Description: ";
  std::getline(std::cin, description);
  tasks.insert(tasks.end(), Task(name, description));
  return 0;
}

void showTasks() {
  int numOfTask = 1;
  for (Task it : tasks) {
    std::cout << "[ ]" << std::endl
              << numOfTask << std::endl
              << "Name: " << it.name << std::endl
              << "Description: " << it.description << std::endl;
  }
}

int main(int argc, char *argv[]) {

  bool keepGoing = true;

  while (keepGoing) {
    switch (menu()) {
    case 1:
      addTask();
      break;
    case 2:
      break;
    case 3:
      showTasks();
      break;
    default:
      keepGoing = false;
    }
  }

  return 0;
}
