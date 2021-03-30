class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {

        if(x+y < z) return false;
        return z == 0|| z%gcd(x, y)==0;
    }
    int gcd(int x, int y)
    {
        return y == 0 ? x: gcd(y, x%y);
    }
};