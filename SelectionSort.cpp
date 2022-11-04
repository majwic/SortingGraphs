#include "SelectionSort.h"

#include <ncurses.h>
#include <unistd.h>

void SelectionSort::sort() {
  int min, temp;
  for (int i = 0; i < vect.size() - 1; ++i) {
    min = i;
    for (int j = i + 1; j < vect.size(); ++j) {
      if (vect[j] < vect[min]) {
	min = j;
      }

      if (vect[min] < vect[i]) {
	temp = vect[min];
	vect[min] = vect[i];
	vect[i] = temp;
      }
    }
  }
}

void SelectionSort::printSort() {
  int min, temp;
  printGraph();
  for (int i = 0; i < vect.size() - 1; ++i) {
    min = i;
    for (int j = i + 1; j < vect.size(); ++j) {
      if (vect[j] < vect[min]) {
	min = j;
      }

      if (vect[min] < vect[i]) {
	refresh();
	usleep(10000);
	temp = vect[min];
	vect[min] = vect[i];
	vect[i] = temp;
	clearPrintBar(min, vect[min]);
	clearPrintBar(i, vect[i]);
      }
    }
  }
}
