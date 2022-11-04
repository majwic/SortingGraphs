#ifndef INLCUDE_HEAPSORT_H
#define INCLUDE_HEAPSORT_H

#include "Sorting.h"

class HeapSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  void heapify(const int n, const int i);
  void printHeapify(const int n, const int i);
  void swap(const int index1, const int index2);
  void printSwap(const int index1, const int index2);
};

#endif
