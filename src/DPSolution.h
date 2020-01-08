#include <vector>
using namespace std;

namespace Phoenix
{
    enum DPSolutionEnum
    {
        Triangle = 1,
        MaxProductSubAry,
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
    };
}