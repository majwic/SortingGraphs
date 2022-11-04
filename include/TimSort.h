#ifndef INCLUDE_TIMSORT_H
#define INCLUDE_TIMSORT_H

#include "Sorting.h"

class TimSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  const int RUN = 32;

  void insertionSort(const int left, const int right);
  void printInsertionSort(const int left, const int right);
  void merge(const int l, const int m, const int r);
  void printMerge(const int l, const int m, const int r);
};

#endif
