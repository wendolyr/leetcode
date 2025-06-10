class Solution {
 public:
  int squareSum(int n) {
    int sum = 0;
    while (n) {
      int last_digit = n % 10;
      sum += last_digit * last_digit;
      n /= 10;
    }

    return sum;
  }

  bool isHappy(int n) {
    int fast = n, slow = n;
    do {
      slow = squareSum(slow);
      fast = squareSum(fast);
      fast = squareSum(fast);
      if (fast == 1) {
        return true;
      }
    } while (fast != slow);

    return false;
  }
};