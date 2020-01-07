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
}