#include "DPSolution.h"
#include <iostream>
using namespace std;
namespace Phoenix
{
void DPSolution::RunTestCase(DPSolutionEnum solutionType)
{
    switch (solutionType)
    {
    case DPSolutionEnum::Triangle:
    {
        vector<vector<int>> input = {
            {2},
            {6, 4},
            {1, 5, 7},
            {1, 1, 8, 3}};
        cout << minimumTotal(input) << endl;
        break;
    }
    case DPSolutionEnum::MaxProductSubAry:
    {
        vector<int> nums = {2, -3, -4, -2};
        cout << maxProduct(nums) << endl;
        vector<int> nums2 = {-2, 0, -2};
        cout << maxProduct(nums2) << endl;
        vector<int> nums3 = {2, 3, -2, 4};
        cout << maxProduct(nums3) << endl;
        break;
    }
    case DPSolutionEnum::SellStockIV:
    {
        vector<int> nums = {2, 4, 1};
        cout << maxProfit(2, nums) << endl;
        vector<int> nums1 = {3, 2, 6, 5, 0, 3};
        cout << maxProfit(2, nums1) << endl;
        vector<int> nums2 = {3, 2, 6, 5, 0, 3, 8, 9, 9, 0, 23, 4, 6, 10};
        cout << maxProfit(5, nums2) << endl;
        break;
    }
    case DPSolutionEnum::LIS:
    {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        cout << lengthOfLIS_2(nums) << endl;
        break;
    }
    }
}

int DPSolution::lengthOfLIS_1(vector<int>& nums) 
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    int res = 1;
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++)
    {
        dp.push_back(1);
    }

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        res = max(dp[i], res);
    }
    return res;
}

int DPSolution::lengthOfLIS_2(vector<int>& nums) 
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    vector<int> lis;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end())
        {
            lis.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
        }
    }
    return lis.size();
}

int DPSolution::climbStairs(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n <= 2)
    {
        return n;
    }

    int first = 1;
    int second = 2;
    int third = 3;
    for (int i = 3; i <= n; i++)
    {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

int DPSolution::minimumTotal(vector<vector<int>> &triangle)
{
    vector<int> helper = triangle[triangle.size() - 1];
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            helper[j] = triangle[i][j] + min(helper[j], helper[j + 1]);
        }
    }
    return helper[0];
}

int DPSolution::maxProduct(vector<int> &nums)
{
    if (nums.size() <= 0)
    {
        return 0;
    }
    vector<vector<int>> dpAry(2, vector<int>{0, 0});
    // [0]存最大值，[1]存最小值
    dpAry[0][0] = dpAry[0][1] = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];
        // 循环复用数组
        int x = i % 2;
        int y = (i + 1) % 2;
        dpAry[x][0] = num >= 0 ? max(num, dpAry[y][0] * num) : max(num, dpAry[y][1] * num);
        dpAry[x][1] = num >= 0 ? min(num, dpAry[y][1] * num) : min(num, dpAry[y][0] * num);
        if (dpAry[x][0] > res)
        {
            res = dpAry[x][0];
        }
    }
    return res;
}

/// 121. Best Time to Buy and Sell Stock
int DPSolution::maxProfit_1(vector<int> &prices)
{
    // 最多只能卖一次
    return maxProfit_K(prices, 1, 0, 0);
}
/// 123. Best Time to Buy and Sell Stock III
int DPSolution::maxProfit_3(vector<int> &prices)

{
    // 最多只能卖一次
    return maxProfit_K(prices, 1, 0, 0);
}
/// 188. Best Time to Buy and Sell Stock IV
int DPSolution::maxProfit(int k, vector<int> &prices)
{
    if (prices.size() <= 1 || k < 1)
    {
        return 0;
    }
    // 如果k超过天数的1/2，就可以当作无限交易了
    if (k > prices.size() / 2)
    {
        // prices.size 返回的是无符号数，for循环条件-1会导致问题，所以需要首先和0比较一下
        if (prices.size() <= 1)
        {
            return 0;
        }
        // 由于每天都可以随便买，所以只要第二天上涨，今天就买，明天就卖，明天卖完之后可以根据后天的情况决定明天买不买
        int profit = 0;
        for (size_t i = 0; i < prices.size() - 1; i++)
        {
            int tomorrowProfix = prices[i + 1] - prices[i];
            if (tomorrowProfix > 0)
            {
                profit += tomorrowProfix;
            }
        }
        return profit;
    }
    // 这里首先要限制下k的范围
    k = min(k, (int)prices.size() / 2);
    vector<vector<vector<int>>> mp3D;
    int minInt = numeric_limits<int>::min();
    // 初始化dp数组 [天、次数（卖出算一次交易）、是否持有]
    for (int i = 0; i < prices.size(); i++)
    {
        vector<vector<int>> tmp2D;
        for (int j = 0; j <= k && j <= prices.size(); j++)
        {
            vector<int> tmp;
            tmp.push_back(0);
            tmp.push_back(minInt);
            tmp2D.push_back(tmp);
        }
        mp3D.push_back(tmp2D);
    }
    // 初始化数组
    for (int j = 0; j <= k && j <= prices.size(); j++)
    {
        mp3D[0][j][0] = 0;
        mp3D[0][j][1] = -prices[0];
    }

    int maxP = -1;
    for (int i = 1; i < prices.size(); i++)
    {
        for (int j = 0; j <= k && j <= i; j++)
        {

            mp3D[i][j][0] = max(mp3D[i - 1][j][0], j >= 1 ? mp3D[i - 1][j - 1][1] + prices[i] : 0);
            mp3D[i][j][1] = max(mp3D[i - 1][j][1], mp3D[i - 1][j][0] - prices[i]);
            // 最后一轮循环在判断大小
            if (i == prices.size() - 1)
            {
                if (maxP < mp3D[i][j][0])
                {
                    maxP = mp3D[i][j][0];
                }
            }
            //{3,2,6,5,0,3,8,9,9,0,23,4,6,10};
            // cout << "[" << i << "," << j << ",0]=" << mp3D[i][j][0] << " ; ";
            // cout << "[" << i << "," << j << ",1]=" << mp3D[i][j][1] << endl;
        }
    }
    return maxP;
}
/// 122. Best Time to Buy and Sell Stock II
// 无限次数的交易，没有冷却时间和交易费
int DPSolution::maxProfit_Infinity(vector<int> &prices, int cd, int fee)
{
    int n = prices.size();
    if (n <= 1)
    {
        return 0;
    }
    int dp[n][2];
    for (int i = 0; i < n; i++)
    {
        if (i - 1 == -1)
        {
            dp[i][0] = 0;
            dp[i][1] = -prices[i] - fee;
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], i - 1 - cd >= 0 ? dp[i - 1 - cd][0] - prices[i] - fee : -prices[i] - fee);
    }
    return dp[n - 1][0];
}
// 通用股票问题，最多交易K次，交易间隔时间cd，每次的交易费用fee
int DPSolution::maxProfit_K(vector<int> &prices, int K, int cd, int fee)
{
    int n = prices.size();
    if (n <= 0)
    {
        return 0;
    }
    if (K > n / 2)
    {
        return maxProfit_Infinity(prices, cd, fee);
    }
    int dp[n][K + 1][2];
    int minInt = numeric_limits<int>::min();
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= K; k++)
        {
            dp[i][k][0] = 0;
            dp[i][k][1] = minInt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = K; k >= 1; k--)
        {
            if (i - 1 == -1)
            {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i];
                continue;
            }
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i - 1][k][1], i - 1 - cd >= 0 ? dp[i - 1 - cd][k - 1][0] - prices[i] - fee : -prices[i] - fee);
        }
    }
    return dp[n - 1][K][0];
}
} // namespace Phoenix