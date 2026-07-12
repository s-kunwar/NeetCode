class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int target=cost.size();
        vector<int>foundcost(target+1);
        foundcost[0]=0;
        foundcost[1]=0;
        
        for(int step=2;step<=target;step++){
            foundcost[step]=min((foundcost[step-2]+cost[step-2]), (foundcost[step-1]+cost[step-1]) );
        }
        return foundcost[target];

    }
};
