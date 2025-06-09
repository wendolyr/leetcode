#include <vector>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    if (fruits.size() < 2) {
      return 1;
    }
    int left = 0, right = 1;
    int first_basket = fruits[left], second_basket = fruits[right++];
    int result = 2;
    int temp = 2;

    while (first_basket == second_basket && right != fruits.size()) {
      second_basket = fruits[right++];
      temp++;
    }
    result = temp;
    while (right != fruits.size()) {
      if (fruits[right] != first_basket && fruits[right] != second_basket) {
        result = max(result, temp);
        left = right - 1;
        temp = 2;
        first_basket = fruits[left];
        while (fruits[--left] == first_basket) {
          temp++;
        }
        second_basket = fruits[right];
        right++;

      } else {
        right++, temp++;
      }
    }

    result = max(result, temp);

    return result;
  }
};