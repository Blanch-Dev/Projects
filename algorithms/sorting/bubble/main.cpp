#include <iostream>

bool isArrayShorted(int arrayInQuestion[]);

int main(int argc, char *argv[]) {

  int arrayToShort[] = {123, 34, 453, 234, 432, 76, 3, 676, 124, 674};

  for (int i = 0; isArrayShorted(arrayToShort); i++) {
    int biggestInMoment = arrayToShort[0];
    std::cout << "A" << std::endl;
    for (int j = 1; j < std::size(arrayToShort) - i - 1; j++) {
      if (biggestInMoment > arrayToShort[j]) {
        arrayToShort[j - 1] = arrayToShort[j];
        arrayToShort[j] = biggestInMoment;
      } else {
        biggestInMoment = arrayToShort[j];
      }
    }
  }

  for (int i : arrayToShort) {
    std::cout << i << std::endl;
  }

  return 0;
}

bool isArrayShorted(int arrayInQuestion[]) {
  for (int i = 1; i < std::size(arrayInQuestion) - 1; i++) {
    if (arrayInQuestion[i - 1] > arrayInQuestion[i]) {
      return false;
    }
  }
  return true;
}
