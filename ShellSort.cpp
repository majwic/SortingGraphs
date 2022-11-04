#include "ShellSort.h"

#include <ncurses.h>
#include <unistd.h>

void ShellSort::sort() {
  int temp;
  int j;
  for (int gap = vect.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < vect.size(); ++i) {
      temp = vect[i];
      for(j = i; j >= gap && vect[j - gap] > temp; j -= gap) {
	vect[j] = vect[j - gap];
      }
      vect[j] = temp;
    }
  }
}

void ShellSort::printSort() {
  printGraph();
  int temp;
  int j;
  for (int gap = vect.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < vect.size(); ++i) {
      temp = vect[i];
      for(j = i; j >= gap && vect[j - gap] > temp; j -= gap) {
	vect[j] = vect[j - gap];
	clearPrintBar(j, vect[j]);
	refresh();
	usleep(10000);
      }
      vect[j] = temp;
      clearPrintBar(j, vect[j]);
      refresh();
      usleep(10000);
    }
  }
}
