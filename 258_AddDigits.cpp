/*258. Add Digits  https://www.zhihu.com/question/30972581
  一个数的数根(digital root)就是它对9的余数*/


class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};