class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1 || n == 2) return n;

        int prevStair = 1;
        int curStair = 2;
        int temp;

        for(int i = 3; i <= n; i++){
            temp = curStair;
            curStair += prevStair;
            prevStair = temp;
        }

        return curStair;
        
    }
};
