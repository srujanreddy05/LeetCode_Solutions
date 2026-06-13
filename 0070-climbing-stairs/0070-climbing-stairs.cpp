class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int prev0 = 0;
        int prev1 = 1;
    for (int i = 1 ; i <= n ; i++){
        int temp =  prev0 + prev1;
        prev0 = prev1;
        prev1 = temp;
    }
    return prev1;
    }

};