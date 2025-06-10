#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maxDifference(string s) {
    unordered_map<char, int> letters;
    for (char i : s) {
      letters[i] += 1;
    }

    int odd = 0, even = INT_MAX;

    for (auto i : letters) {
      if (i.second % 2 == 0 && i.second < even) {
        even = i.second;
      } else if (i.second % 2 == 1 && i.second > odd) {
        odd = i.second;
      }
    }
    return odd - even;
  }
};