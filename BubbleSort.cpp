#include "BubbleSort.h"

#include <ncurses.h>
#include <unistd.h>

void BubbleSort::sort() {
  int temp;
  for (int i = 0; i < vect.size() - 1; ++i) {
    for (int j = 0; j < vect.size() - i - 1; ++j) {
      if (vect[j] > vect[j + 1]) {
	temp = vect[j];
	vect[j] = vect[j + 1];
	vect[j + 1] = temp;
      }
    }
  }
}

void BubbleSort::printSort() {
  int temp;
  printGraph();
  for (int i = 0; i < vect.size() - 1; ++i) {
    for (int j = 0; j < vect.size() - i - 1; ++j) {
      if (vect[j] > vect[j + 1]) {
	refresh();
	usleep(10000);
	temp = vect[j];
	vect[j] = vect[j + 1];
	vect[j + 1] = temp;
	clearPrintBar(j, vect[j]);
	clearPrintBar(j + 1, vect[j + 1]);
      }
    }
  }
}
