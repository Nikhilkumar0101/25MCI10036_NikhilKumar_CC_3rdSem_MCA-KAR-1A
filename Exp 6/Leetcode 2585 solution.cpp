#define mod 1000000007;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(auto t : types){
            int counts = t[0];
            int marks = t[1];
            
            for(int i=target; i>=1; i--){
                for(int count=1; count <= counts; count++){
                    if(i-marks*count >= 0)
                        dp[i] = (dp[i] + dp[i - marks*count])%mod;
                }
            }
        }
        
        return dp[target];
    }
};