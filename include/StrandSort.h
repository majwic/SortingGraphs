#ifndef INCLUDE_STRANDSORT_H
#define INCLUDE_STRANDSORT_H

#include "Sorting.h"

#include <vector>

class StrandSort : public Sorting {
 public:
  void sort();
  void printSort();
 private:
  void strandSort(std::vector<int> &nVect);
  void merge(std::vector<int> &subVect);
  void printStrandSort(std::vector<int> &nVect);
  void printMerge(std::vector<int> &subVect);
 
};

#endif
