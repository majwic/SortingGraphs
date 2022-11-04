#ifndef INCLUDE_PANCAKESORT_H
#define INCLUDE_PANCAKESORT_H

#include "Sorting.h"

class PancakeSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  void flip(int index);
  void printFlip(int index);
  int findMax(const int size);
};

#endif 
