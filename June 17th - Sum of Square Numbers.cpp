// TC - O(sqrt(c)
// SC - O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        long x = sqrt(c);
        long y = 0;
        while(x>=y) {
            if(x*x + y*y == c) return true;
            else if(x*x + y*y > c) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};
