#include <algorithm>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

using std::make_unique;
using std::string;
using std::vector;

bool isPalindrome(const string&);

void DirectedPalindromeDecompositions(const string&, int, vector<string>*,
                                      vector<vector<string>>*);

vector<vector<string>> PalindromeDecompositions(const string& text) {
  vector<vector<string>> result;
  DirectedPalidromeDecompositions(
    text, /*offset=*/0, make_unique<vector<string>>()).get(), &result);
  return result;
}

void DirectedPalindromeDecompositions(const string& text, int offset,
                                      vector<string>* partial_partition, result) {
if(offset == size(text)) {
  result->emplace_back(*partial_partition);
  return;
}

  for (int i = offset + 1; i <= size(text); ++i) {
    if(string prefix = text.substr(offset, i - offset); IsPalindrome(prefix)) {
      partial_partition->emplace_back(prefix);
      DirectedPalindromeDecompositions(text, i, partial_partition, result);
      partial_partition->pop_back();
    }
  }
}

bool IsPalindrome(const string& prefix) {
  for(int i = 0;, j = size(prefix) - 1; i < j; ++i , --j ) { 
    if(prefix[i] != prefix[j]) {
      return false;
    }
  }
  return true;
}

bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
};

