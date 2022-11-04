#include "MergeSort.h"

#include <vector>
#include <ncurses.h>
#include <unistd.h>

void MergeSort::sort() {
  mergeSort(0, vect.size() - 1);
}

void MergeSort::printSort() {
  printGraph();
  printMergeSort(0, vect.size() - 1);
}

void MergeSort::merge(const int start, const int mid, const int end) {
  std::vector<int> temp;

  int i, j;
  i = start;
  j = mid + 1;

  while (i <= mid && j <= end) {
    if (vect[i] <= vect[j]) {
      temp.push_back(vect[i]);
      i++;
    } else {
      temp.push_back(vect[j]);
      j++;
    }
  }

  while (i <= mid) {
    temp.push_back(vect[i]);
    i++;
  }

  while (j <= end) {
    temp.push_back(vect[j]);
    j++;
  }

  for (i = start; i <= end; ++i) {
    vect[i] = temp[i - start];
  }
}

void MergeSort::mergeSort(const int start, const int end) {
  if (start < end) {
    int m = (start + end) / 2;
    mergeSort(start, m);
    mergeSort(m + 1, end);
    merge(start, m, end);
  }
}

void MergeSort::printMerge(const int start, const int mid, const int end) {
  std::vector<int> temp;

  int i, j;
  i = start;
  j = mid + 1;

  while (i <= mid && j <= end) {
    if (vect[i] <= vect[j]) {
      temp.push_back(vect[i]);
      i++;
    } else {
      temp.push_back(vect[j]);
      j++;
    }
  }

  while (i <= mid) {
    temp.push_back(vect[i]);
    i++;
  }

  while (j <= end) {
    temp.push_back(vect[j]);
    j++;
  }

  for (i = start; i <= end; ++i) {
    vect[i] = temp[i - start];
    refresh();
    usleep(10000);
    clearPrintBar(i, vect[i]);
  }
}

void MergeSort::printMergeSort(const int start, const int end) {
  if (start < end) {
    int m = (start + end) / 2;
    printMergeSort(start, m);
    printMergeSort(m + 1, end);
    printMerge(start, m, end);
  }
}
