#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> result(code.size(), 0);
    int sum = 0, size = code.size();
    if (k != 0) {
      int left = k > 0 ? 1 : size + k;
      int right = k > 0 ? k : size - 1;
      for (int i = left; i <= right; i++) {
        sum += code[i];
      }
      result[0] = sum;
      for (int i = 1; i < size; i++) {
        sum -= code[left];
        left = (left + 1) % size;
        right = (right + 1) % size;
        sum += code[right];
        result[i] = sum;
      }
    }

    return result;
  }
};