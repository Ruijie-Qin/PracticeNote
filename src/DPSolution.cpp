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
                    {6,4},
                    {1,5,7},
                    {1,1,8,3}
                };
                cout << minimumTotal(input) << endl;
                break;
            }
            case DPSolutionEnum::MaxProductSubAry:
            {
                vector<int> nums = {2,-3,-4,-2};
                cout << maxProduct(nums) << endl;
                vector<int> nums2 = {-2,0,-2};
                cout << maxProduct(nums2) << endl;
                vector<int> nums3 = {2,3,-2,4};
                cout << maxProduct(nums3) << endl;
                break;
            }
        }
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

    int DPSolution::minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> helper = triangle[triangle.size()-1];
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                helper[j] = triangle[i][j] + min(helper[j], helper[j+1]);
            }
        }
        return helper[0];
    }

    int DPSolution::maxProduct(vector<int>& nums)
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
            int x = i%2;
            int y = (i+1)%2;
            dpAry[x][0] = num >= 0 ? max(num, dpAry[y][0] * num) : max(num, dpAry[y][1] * num);
            dpAry[x][1] = num >= 0 ? min(num, dpAry[y][1] * num) : min(num, dpAry[y][0] * num);
            if (dpAry[x][0] > res)
            {
                res = dpAry[x][0];
            }
        }
        return res;
    }
}