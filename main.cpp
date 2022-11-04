#include <ncurses.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <chrono>

#include "HeapSort.h"
#include "QuickSort.h"
#include "StrandSort.h"
#include "PancakeSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "Sorting.h"

int main(int argc, char *argv[]) {
  std::vector<int> mess;
  int messLength = 50;
  std::vector<int> messLong;
  int messLongLength = 10000;

  for (int i = 0; i < messLength; ++i) {
    mess.push_back(i + 1);
  }

  for (int i = 0; i < messLongLength; ++i) {
    messLong.push_back(i + 1);
  }

  std::random_shuffle(mess.begin(), mess.end());
  std::random_shuffle(messLong.begin(), messLong.end());
  
  system("resize -s 50 150");
  initscr();
  raw();
  noecho();
  cbreak();
  curs_set(0);

  HeapSort hpSort;
  hpSort.setVect(mess);
  clear();
  hpSort.printSort();
  mvprintw(0, 0, "%d ms -- HeapSort", hpSort.getTime(messLong));

  getch();
  
  QuickSort qikSort;
  qikSort.setVect(mess);
  clear();
  qikSort.printSort();
  mvprintw(0, 0, "%d ms -- QuickSort", qikSort.getTime(messLong));

  getch();
  
  StrandSort stndSort;
  stndSort.setVect(mess);
  clear();
  stndSort.printSort();
  mvprintw(0, 0, "%d ms -- StrandSort", stndSort.getTime(messLong));

  getch();
  
  PancakeSort pnkSort;
  pnkSort.setVect(mess);
  clear();
  pnkSort.printSort();
  mvprintw(0, 0, "%d ms -- PancakeSort", pnkSort.getTime(messLong));
  
  getch();

  MergeSort mrgSort;
  mrgSort.setVect(mess);
  clear();
  mrgSort.printSort();
  mvprintw(0, 0, "%d ms -- MergeSort", mrgSort.getTime(messLong));
  
  getch();
  
  BubbleSort bblSort;
  bblSort.setVect(mess);
  clear();
  bblSort.printSort();
  mvprintw(0, 0, "%d ms -- BubbleSort", bblSort.getTime(messLong));

  getch();

  InsertionSort inrtSort;
  inrtSort.setVect(mess);
  clear();
  inrtSort.printSort();
  mvprintw(0, 0, "%d ms -- InsertionSort", inrtSort.getTime(messLong));

  getch();

  SelectionSort slctSort;
  slctSort.setVect(mess);
  clear();
  slctSort.printSort();
  mvprintw(0, 0, "%d ms -- SelectionSort", slctSort.getTime(messLong));

  getch();
  
  endwin();
  
  return 0;
}
