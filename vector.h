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
  protected:
  private:
};

#endif //VECTOR_H
