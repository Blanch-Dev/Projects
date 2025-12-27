#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Task {
public:
  std::string name;
  std::string description;
  bool finished;
  Task(std::string name, std::string description) {
    this->name = name;
    this->description = description;
    finished = false;
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
  std::cin.ignore();
  std::cout << std::endl;
  return option;
}

int addTask(std::string *name, std::string *description) {
  tasks.insert(tasks.end(), Task(*name, *description));
  return 0;
}

int deleteTask(int taskId) {
  try {
    tasks.at(taskId - 1).finished = true;
    return 0;
  } catch (const std::exception) {
    std::cout << "Task ID is not valid.";
    return 1;
  }
}

void showTasks() {
  int numOfTask = 1;
  for (Task it : tasks) {
    std::cout << "[ ]  " << numOfTask << std::endl
              << "Name: " << it.name << std::endl
              << "Description: " << it.description << std::endl;
  }
}

void mainLoop() {
  bool keepGoing = true;

  while (keepGoing) {
    switch (menu()) {
    case 1: {
      std::string name, description;
      std::cout << "Name: ";
      std::getline(std::cin, name);
      std::cout << "Description: ";
      std::getline(std::cin, description);
      addTask(&name, &description);
      break;
    }
    case 2: {
      int taskId;
      std::cout << "What is the ID of the task you want to end: ";
      std::cin >> taskId;
      deleteTask(taskId);
      break;
    }
    case 3: {
      showTasks();
      break;
    }
    default:
      keepGoing = false;
    }
  }
}

int main(int argc, char *argv[]) {

  mainLoop();

  return 0;
}
