#include "InsertionSort.h"

#include <ncurses.h>
#include <unistd.h>

void InsertionSort::sort() {
  int key, j;
  for (int i = 1; i < vect.size(); ++i) {
    key = vect[i];
    j = i - 1;

    while (j >= 0 && vect[j] > key) {
      vect[j + 1] = vect[j];
      j = j - 1;
    }
    vect[j + 1] = key;
  }
}

void InsertionSort::printSort() {
  int key, j;
  printGraph();
  for (int i = 1; i < vect.size(); ++i) {
    key = vect[i];
    j = i - 1;

    while (j >= 0 && vect[j] > key) {
      refresh();
      usleep(10000);
      vect[j + 1] = vect[j];
      clearPrintBar(j + 1, vect[j + 1]);
      j = j - 1;
    }
    vect[j + 1] = key;
    clearPrintBar(j + 1, vect[j + 1]);
  }
}
