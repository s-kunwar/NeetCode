class Solution {
public:
    int stairs(int n){
        if(n<2) return 1;
        return stairs(n-1)+stairs(n-2);
    }
    int climbStairs(int n) {
        vector<int>steps(n+1);
        return steps[n]=stairs(n-1)+stairs(n-2);
    }

};
