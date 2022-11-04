#include "QuickSort.h"

#include <ncurses.h>
#include <unistd.h>

void QuickSort::sort() {
  quickSort(0, vect.size() - 1);
}

void QuickSort::printSort() {
  printGraph();
  printQuickSort(0, vect.size() - 1);
}

void QuickSort::quickSort(const int low, const int high) {
  if (low < high) {
    int part = partition(low, high);
    quickSort(low, part - 1);
    quickSort(part + 1, high);
  }
}

void QuickSort::printQuickSort(const int low, const int high) {
  if (low < high) {
    int part = printPartition(low, high);
    printQuickSort(low, part - 1);
    printQuickSort(part + 1, high);
  }
}

int QuickSort::partition(const int low, const int high) {
  int pivot = vect[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; ++j) {
    if (vect[j] < pivot) {
      i++;
      swap(i, j);
    }
  }
  swap(i + 1, high);
  return (i + 1);
}

int QuickSort::printPartition(const int low, const int high) {
  int pivot = vect[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (vect[j] < pivot) {
      i++;
      printSwap(i, j);
    }
  }
  printSwap(i + 1, high);
  return (i + 1);
}

void QuickSort::swap(const int index1, const int index2) {
  int temp = vect[index1];
  vect[index1] = vect[index2];
  vect[index2] = temp;
}

void QuickSort::printSwap(const int index1, const int index2) {
  refresh();
  usleep(10000);
  int temp = vect[index1];
  vect[index1] = vect[index2];
  vect[index2] = temp;
  clearPrintBar(index1, vect[index1]);
  clearPrintBar(index2, vect[index2]);
}
