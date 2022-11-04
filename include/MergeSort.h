#ifndef INLCUDE_MERGESORT_H
#define INCLUDE_MERGESORT_H

#include "Sorting.h"
#include <vector>

class MergeSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  void merge(const int start, const int mid, const int end);
  void printMerge(const int start, const int mid, const int end);
  void mergeSort(const int start, const int end);
  void printMergeSort(const int start, const int end);
};

#endif
