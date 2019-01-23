#ifndef VECTOR_H
#define VECTOR_H
#include<vector>

class vectors
{
  public:
    vectors();
    ~vectors();
    void vectorsMain();
    void printVector(std::vector<int> practiceVec);
    void printArray(int practiceArray[10]);
    void printArray2(int msArray[7]);
    std::vector<int> addElement(std::vector<int> practiceVec);
    std::vector<int> insertElement(std::vector<int> practiceVec);
    std::vector<int> insertAt(std::vector<int> practiceVec);
    std::vector<int> deleteElement(std::vector<int> practiceVec);
    int arrayInsertDelete(int practiceArray[10]);
    void mergeSortMerge(int *msArray, int start, int middle, int end);
    void mergeSort(int *msArray, int start, int end);
    std::vector<std::tuple<int,int>> notempSwap(int a, int b);
  protected:
  private:
};

#endif //VECTOR_H
