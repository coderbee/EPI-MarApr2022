#include <algorithm>
#include <vector>

using std::vector;

int CountSubarrayInversions(int, int, vector<int>*);
int MergeSortAndCountInversionsAcrossSubarrays(int, int, int, vector<int>*);

int CountInversions(vector<int> A) {
  return CountSubarrayInversions(0, size(A), &A);
}

//Return the number of inversions in (*A_ptr)[start, finish - 1].
int CountSubarrayInversions(int start, int finish, vector<int>* A_ptr) {
  if(finish - start <= 1 ) {
    return 0;
  }
  
  int mid = start + ((finish - start) / 2 );
  return CountSubarrayInversions(start, mid, A_Ptr) +
          CountSubarrayInversions(mid, finish, A_Ptr) +
          MergeSortAndCountInversionsAcrossSubarrays(start, mid, finish, A_Ptr);
}

//Merge two subarrays A[start, mid - 1] and A[mid, finish - 1] into 
//A[start, finish - 1] and return the number of inversions across A[start,
// mid - 1] and A[mid, finish - 1].
int MergeSortAndCountInversionsAcrossSubarrays(int start, int mid, int finish,
                                               vector<int>* A_Ptr) {
  vector<int> sorted_A;
  int left_start = start, right_start = mid, inversion_count = 0;
  
  vector<int>& A = *A_ptr;
  while (left_start < mid && right_start < finish) {
    if(A[left_start] <= A[right_start]) {
      sorted_A.emplace_back(A[left_start++]);
    } else {
      //A[left, start, mid - 1] are the inversions of A[right_start].
      inversion_count += mid - left_start;
      sorted_A.emplace_back(A[right_start++]);
    }
  }
  copy(begin(A) + left_start, begin(A) + mid, back_inserter(sorted_A));
  copy(begin(A) + right_start, begin(A) + finish, back_inserter(sorted_A));
  
  //Updates A with sorted_A.
  copy(begin(sorted_A), end(sorted_A), begin(A) + start);
  return inversion_count;
}
