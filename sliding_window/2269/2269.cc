#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int divisorSubstrings(int num, int k) {
    int result = 0;
    string dub = to_string(num);
    int left = 0, right = k - 1;
    while (right != dub.size()) {
      int sub = 0;
      for (int i = left; i <= right; i++) {
        sub = sub * 10 + (dub[i] - '0');
      }

      if (sub != 0 && num % sub == 0) {
        result++;
      }
      left++, right++;
    }
    return result;
  }
};