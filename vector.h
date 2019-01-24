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
    void printArray(int practiceArray[],int size);
    std::vector<int> addElement(std::vector<int> practiceVec);
    std::vector<int> insertElement(std::vector<int> practiceVec);
    std::vector<int> insertAt(std::vector<int> practiceVec);
    std::vector<int> deleteElement(std::vector<int> practiceVec);
    int arrayInsertDelete(int practiceArray[10]);
    void mergeSortMerge(int *msArray, int start, int middle, int end);
    void mergeSort(int *msArray, int start, int end);
    std::vector<std::tuple<int,int>> notempSwap(int a, int b);
    void quickSort(int *qsArray, int low, int high);
    int quickSortPart(int *qsArray, int low, int high);
    void arraySwap(int *a, int *b);
  protected:
  private:
};

#endif //VECTOR_H
