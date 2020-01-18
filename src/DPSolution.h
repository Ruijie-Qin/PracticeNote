#include <vector>
#include <iostream>
using namespace std;

namespace Phoenix
{
    enum DPSolutionEnum
    {
        Triangle = 1,
        MaxProductSubAry,
        SellStockIV,
        LIS,
    };

    class DPSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(DPSolutionEnum solutionType);
        /// 70. Climbing Stairs
        int climbStairs(int n);
        /// 120. Triangle
        int minimumTotal(vector<vector<int>>& triangle);
        /// 152. Maximum Product Subarray
        int maxProduct(vector<int>& nums);
        /// 121. Best Time to Buy and Sell Stock
        int maxProfit_1(vector<int>& prices);
        /// 123. Best Time to Buy and Sell Stock III
        int maxProfit_3(vector<int>& prices);
        /// 188. Best Time to Buy and Sell Stock IV
        int maxProfit(int k, vector<int>& prices);
        /// 300. Longest Increasing Subsequence
        int lengthOfLIS_1(vector<int>& nums); // DP
        int lengthOfLIS_2(vector<int>& nums); // O(Nlog(N))
        /// 322. Coin Change
        int coinChange(vector<int>& coins, int amount);
        /// 72. Edit Distance
        int minDistance(string word1, string word2);
    private:
        /// 122. Best Time to Buy and Sell Stock II
        // 无限次数的交易，没有冷却时间和交易费
        int maxProfit_Infinity(vector<int>& prices, int cd, int fee);
        // 通用股票问题，最多交易K次，交易间隔时间cd，每次的交易费用fee
        int maxProfit_K(vector<int>& prices, int K, int cd, int fee);
    };
}