#include <test_framework/generic_test.h"

int SquareRoot(int k) {
  int left = 0, right = k;
  //Candidate interval [left, right] where everything before left has
  // square <= k, and everything after right has square > k.
  while (left <= right) {
    long long mid = left + ((right - left) / 2);
    if (long long mid_squared = mid * mid; mid_squared <= k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left - 1;
}

