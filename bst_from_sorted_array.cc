#include <memory>
#include <vector>

#include"bst_node.h"

usung std::make_unique;
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedSubarray(const vector<int>&,
                                                             int, int);

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedArray(
  const vector<int>& A) {
  return BuildMinHeightBSTFromSortedSubarray(A, 0, size(A));
}

//Build a min-height BST over the entries in A[start, end - 1].
unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedSubarray(
  const vector<int>& A, int start, int end) {
  if(start >= end) {
    return nullptr;
  }
  int mid = start + (end -start) / 2 ;
  return make_unique<BstNode<int>>(
    A[mid], BuildMinHeightBSTFromSortedSubarray(A, start, mid),
    BuildMinHeightBSTFromSortedSubarray(A, mid + 1, end));
}

int BuildMinHeightBSTFromSortedArrayWrapper(TimedExecutor& executor,
                                            const vector<int>& A) {
  auto result = 
    executor.Run([&] { return BuildMinHeightBSTFromSortedArray(A); } );
  
  if(test_framework::GenerateInorder(result) != A) {
    throw TestFailure("Result binary tree mismatches input array");
  }
  return test_framework::BinaryTreeHeight(result);
}



