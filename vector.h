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
    std::vector<int> addElement(std::vector<int> practiceVec);
    std::vector<int> insertElement(std::vector<int> practiceVec);
    std::vector<int> insertAt(std::vector<int> practiceVec);
    std::vector<int> deleteElement(std::vector<int> practiceVec);
    int arrayInsertDelete(int practiceArray[10]);
    void mergeSortMerge(int *msVector, int start, int middle, int end);
    void mergeSort(int *msVector, int start, int end);
    int msVector[7] = {38,27,43,3,9,82,10};
  protected:
  private:
};

#endif //VECTOR_H
