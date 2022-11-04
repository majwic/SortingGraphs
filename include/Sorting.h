#ifndef INCLUDE_SORTING_H
#define INCLUDE_SORTING_H

#include <vector>

class Sorting {
 protected:
  std::vector<int> vect;
 private:
  void printBar(const int column, const int value);
 public:
  virtual void sort() {}
  virtual void printSort() {}

  void setVect(const std::vector<int> nVect);
  void printGraph();
  int getTime(std::vector<int> mess);
  void clearPrintBar(const int column, const int value);
};

#endif
