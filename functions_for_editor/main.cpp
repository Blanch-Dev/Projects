#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string readArchive(std::string archivePath) {
  std::ifstream File(archivePath);
  std::string textFromFile, nextFileLine;

  while (std::getline(File, nextFileLine)) {
    textFromFile = textFromFile + nextFileLine + "\n";
  }

  File.close();

  return textFromFile;
}

bool createNewDirectory(std::string nameOfNewDirectory) {
  std::filesystem::path newPath = nameOfNewDirectory;

  if (!std::filesystem::exists(newPath)) {
    std::filesystem::create_directory(newPath);
    return true;
  }
  return false;
}

bool createNewFile(std::string nameOfNewDirectory, std::string nameOfNewFile) {
  std::filesystem::path newArchive = nameOfNewDirectory + "/" + nameOfNewFile;
  std::ofstream File(newArchive);
  if (File.is_open()) {
    return true;
  }
  return false;
}

std::vector<std::string> archivesInFolder(std::string directoryPath) {
  std::vector<std::string> archivesInFolder;

  if (std::filesystem::exists(directoryPath) &&
      std::filesystem::is_directory(directoryPath)) {
    for (const auto &entry :
         std::filesystem::directory_iterator(directoryPath)) {
      archivesInFolder.push_back(entry.path());
    }
  }

  return archivesInFolder;
}

int main(int argc, char *argv[]) {

  // std::cout << readArchive("./try.cpp");

  for (std::string i : archivesInFolder("tryFolder")) {
    std::cout << "File: " << i << std::endl;
  }

  return 0;
}
