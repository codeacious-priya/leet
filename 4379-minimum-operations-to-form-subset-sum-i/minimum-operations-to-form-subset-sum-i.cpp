class Solution {
public:

    const int INF = 1e9;

    // Returns {value, minimum operations}
    vector<pair<int, int>> getValues(int x, int sum) {

        vector<pair<int, int>> res;

        // Division: x, x/2, x/4, ...
        int y = x;
        int cost = 0;

        while (y > 0) {

            if (y <= sum) {
                res.push_back({y, cost});
            }

            y /= 2;
            cost++;
        }

        // Multiplication: x, 2x, 4x, ...
        y = x;
        cost = 0;

        while (y <= sum) {

            res.push_back({y, cost});

            if (y > sum / 2)
                break;

            y *= 2;
            cost++;
        }

        return res;
    }


    int solve(int i,
              int target,
              vector<vector<pair<int, int>>>& options,
              vector<vector<int>>& dp) {

        // We formed the required sum
        if (target == 0)
            return 0;

        // No elements left
        if (i == options.size())
            return INF;

        // Already calculated
        if (dp[i][target] != -1)
            return dp[i][target];


        // Choice 1: Don't take current element
        int ans = solve(i + 1, target, options, dp);


        // Choice 2: Take current element
        for (auto [value, cost] : options[i]) {

            if (value <= target) {

                int next = solve(
                    i + 1,
                    target - value,
                    options,
                    dp
                );

                if (next != INF) {
                    ans = min(ans, cost + next);
                }
            }
        }

        return dp[i][target] = ans;
    }


    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();

        vector<vector<pair<int, int>>> options(n);

        // Generate possible values for every element
        for (int i = 0; i < n; i++) {
            options[i] = getValues(nums[i], sum);
        }


        // dp[i][target]
        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, -1)
        );


        int ans = solve(
            0,
            sum,
            options,
            dp
        );


        return ans == INF ? -1 : ans;
    }
};