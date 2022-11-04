#include "Sorting.h"

#include <ncurses.h>
#include <iostream>
#include <chrono>

void Sorting::setVect(const std::vector<int> nVect) {
  vect = nVect;
}

void Sorting::printBar(const int column, const int value) {
  int nColumn = column * 3;
  
  for (int i = 0; i < value; ++i) {
    mvprintw(LINES - 1 - i, nColumn, "x");
    mvprintw(LINES - 1 - i, nColumn + 1, "x");
  }
}

void Sorting::clearPrintBar(const int column, const int value) {
  int nColumn = column * 3;

  for (int i = 0; i < LINES; ++i) {
    mvprintw(LINES - 1 - i, nColumn, " ");
    mvprintw(LINES - 1 - i, nColumn + 1, " ");
  }
  
  for (int i = 0; i < value; ++i) {
    mvprintw(LINES - 1 - i, nColumn, "x");
    mvprintw(LINES - 1 - i, nColumn + 1, "x");
  }
}

void Sorting::printGraph() {
  clear();
  for (int i = 0; i < vect.size(); ++i) {
    printBar(i, vect[i]);
  }
}

int Sorting::getTime(std::vector<int> mess) {
  setVect(mess);
  auto start = std::chrono::system_clock::now();
  sort();
  auto end = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
