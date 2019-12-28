#include "DivideConquer.h"
#include <iostream>
#include <unordered_map>
using namespace std;

namespace Phoenix
{
    void DivideConquerSolution::RunTestCase(DivideConquerSolutionEnum solutionType)
    {
        switch (solutionType)
        {
            case DivideConquerSolutionEnum::PowN:
            {
                cout << myPow_2(-2, 9) << endl;
                cout << myPow_2(-2, -4) << endl;
                int n =  -2147483648;
                long long N = -n;
                cout << N << endl;
                for (int i = 1; i < 20; i++)
                {
                    N >>= 1;
                    cout << N << endl;
                }
                cout << myPow_2(2, -2147483648) << endl;
                break;
            }
            case DivideConquerSolutionEnum::Majority:
            {
                vector<int> num = vector<int>{0,1,1,2,2,2,1,1,3,3,4};
                cout << majorityElement(num) << endl;
                break;
            }
            default:
                break;
        }
    }

    double DivideConquerSolution::myPow_1(double x, int n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        // 如果按照下面的方式写，当x=-2147483648时，-x的值仍然是-2147483648
        // if (n < 0)
        // {
        //     x = 1/x;
        //     n = -n;
        // }
        if (n == -1)
        {
            return 1/x;
        }

        double y = myPow_1(x, n/2);
        if (n % 2 == 0)
        {
            return y*y;
        }
        else
        {
            return y*y*(n > 0 ? x : 1/x);
        }
    }
    // 非递归写法
    double DivideConquerSolution::myPow_2(double x, int n)
    {
        long long N = n;
        if (n < 0)
        {
            x = 1/x;
            N = -N;
        }

        double pow = 1;
        while (N)
        {
            if ((N & 1) == 1)
            {
                pow *= x;
            }
            x *= x;
            N >>= 1;
        }
        return pow;
    }

    int DivideConquerSolution::majorityElement(vector<int>& nums) 
    {
        // key: array[i], value: count
        unordered_map<int, int> mapHelper;
        int value;
        for (int i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            if (mapHelper.find(value) != mapHelper.end())
            {
                mapHelper[value]++;
            }
            else
            {
                mapHelper[value] = 1;
            }
        }
        int maxValue = 0;
        int maxCount = 0;
        for (auto iter = mapHelper.begin(); iter != mapHelper.end(); iter++)
        {
            if (iter->second > maxCount)
            {
                maxValue = iter->first;
                maxCount = iter->second;
            }
        }
        return maxValue;
    }

    int DivideConquerSolution::maxProfit(vector<int>& prices)
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
            int tomorrowProfix = prices[i+1] - prices[i];
            if (tomorrowProfix > 0)
            {
                profit += tomorrowProfix;
            }
        }
        return profit;
    }
}
 