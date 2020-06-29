/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (47.14%)
 * Likes:    1429
 * Dislikes: 83
 * Total Accepted:    68.1K
 * Total Submissions: 142.7K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins. 
 * 
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score. 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2
 * (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5,
 * then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 +
 * 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you
 * need to return False.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose
 * 233.Finally, player 1 has more score (234) than player 2 (12), so you need
 * to return True representing player1 can win.
 * 
 * 
 * 
 * Note:
 * 
 * 1 
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[20][20];
    long long dfs(vector<int>& nums, int i, int j, int remain_sum) {
        if (i > j)
            return 0;
        if (dp[i][j] == -1)
            dp[i][j] = max(remain_sum - dfs(nums, i + 1, j, remain_sum - nums[i]),
                           remain_sum - dfs(nums, i, j - 1, remain_sum - nums[j]));
        return dp[i][j];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        return (2 * dfs(nums, 0, n - 1, sum) >= sum);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{0, 0, 0};
    cout << s.PredictTheWinner(nums) << endl;
    return 0;
}