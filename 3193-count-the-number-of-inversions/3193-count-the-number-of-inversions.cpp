
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int MOD = 1000000007;

        // Store required inversion count for each prefix
        vector<int> required(n, -1);

        for (auto r : requirements) {
            required[r[0]] = r[1];
        }

        // Maximum inversion count we need to consider
        int maxCount = 0;
        for (auto r : requirements) {
            maxCount = max(maxCount, r[1]);
        }

        // dp[i][j] = number of ways for prefix ending at i
        // to have exactly j inversions
        vector<vector<int>> dp(n, vector<int>(maxCount + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            long long ways = 0;

            for (int count = 0; count <= maxCount; count++) {
                ways = 0;

                // New element can create 0 to i new inversions
                for (int add = 0; add <= i && add <= count; add++) {
                    ways += dp[i - 1][count - add];
                    ways %= MOD;
                }

                dp[i][count] = ways;
            }

            // If this prefix has a requirement, keep only that count
            if (required[i] != -1) {
                int need = required[i];

                for (int count = 0; count <= maxCount; count++) {
                    if (count != need) {
                        dp[i][count] = 0;
                    }
                }
            }
        }

        // Add all valid ways for the complete array
        int answer = 0;

        for (int count = 0; count <= maxCount; count++) {
            answer = (answer + dp[n - 1][count]) % MOD;
        }

        return answer;
    }
};
