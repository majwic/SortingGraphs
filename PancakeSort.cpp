#include "PancakeSort.h"

#include <ncurses.h>
#include <unistd.h>

void PancakeSort::sort() {
  for (int currSize = vect.size(); currSize > 1; --currSize) {
    int maxIndex = findMax(currSize);

    if (maxIndex != currSize - 1) {
      flip(maxIndex);
      flip(currSize - 1);
    }
  }
}

void PancakeSort::printSort() {
  printGraph();
  for (int currSize = vect.size(); currSize > 1; --currSize) {
    int maxIndex = findMax(currSize);

    if (maxIndex != currSize - 1) {
      printFlip(maxIndex);
      printFlip(currSize - 1);
    }
  }
}

void PancakeSort::flip(int index) {
  int temp, start = 0;
  while (start < index) {
    temp = vect[start];
    vect[start] = vect[index];
    vect[index] = temp;
    start++;
    index--;
  }
}

void PancakeSort::printFlip(int index) {
  int temp, start = 0;
  while (start < index) {
    refresh();
    usleep(10000);
    temp = vect[start];
    vect[start] = vect[index];
    vect[index] = temp;
    clearPrintBar(start, vect[start]);
    clearPrintBar(index, vect[index]);
    start++;
    index--;
  }
}

int PancakeSort::findMax(const int size) {
  int maxIndex, i;
  for (maxIndex = 0, i = 0; i < size; ++i) {
    if (vect[i] > vect[maxIndex]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}
