#ifndef INCLUDE_QUICKSORT_H
#define INCLUDE_QUICKSORT_H

#include "Sorting.h"

class QuickSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  void quickSort(const int low, const int high);
  int partition(const int low, const int high);
  void printQuickSort(const int low, const int high);
  int printPartition(const int low, const int high);
  void swap(const int index1, const int index2);
  void printSwap(const int index1, const int index2);
};

#endif
