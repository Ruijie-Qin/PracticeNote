
#include <vector>
using namespace std;

namespace Phoenix
{
    enum DivideConquerSolutionEnum
    {
        PowN = 1,
        Majority,
    };


    class DivideConquerSolution
    {
    public:
        /// 执行测试案例
		void RunTestCase(DivideConquerSolutionEnum solutionType = DivideConquerSolutionEnum::PowN);
        /// Pow(x, n)
        double myPow_1(double x, int n); // 递归
        double myPow_2(double x, int n); // 非递归
        /// Majority
        int majorityElement(vector<int>& nums);
        /// leetcode 122: Best Time to Buy and Sell Stock II
        /// 这个题目可以使用贪心算法
        int maxProfit(vector<int>& prices);
    };
}