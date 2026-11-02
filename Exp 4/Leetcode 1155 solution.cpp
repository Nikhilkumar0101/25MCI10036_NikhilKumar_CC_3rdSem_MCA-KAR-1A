class Solution {
private:
    int memo[31][1001];
    int mod = 1e9 + 7;

    long long solve(int diceLeft, int k, int targetLeft) {
        if (diceLeft == 0) {
            return targetLeft == 0 ? 1 : 0;
        }
        if (targetLeft < 0) {
            return 0;
        }
        
        if (memo[diceLeft][targetLeft] != -1) {
            return memo[diceLeft][targetLeft];
        }

        long long ways = 0;
        for (int face = 1; face <= k; ++face) {
            ways = (ways + solve(diceLeft - 1, k, targetLeft - face)) % mod;
        }

        return memo[diceLeft][targetLeft] = ways;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        memset(memo, -1, sizeof(memo));
        return solve(n, k, target);
    }
};