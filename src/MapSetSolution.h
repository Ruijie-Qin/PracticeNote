#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

namespace Phoenix
{
    enum MapSetSolutionEnum
    {
        TwoSum = 1,
        ThreeSum,
        KSum,
    };

    class MapSetSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(MapSetSolutionEnum solutionType = MapSetSolutionEnum::TwoSum);
        /// leetcode: Two Sum
        static vector<int> twoSum(vector<int>& nums, int target);
        /// 3Sum
        static vector<vector<int>> threeSum(vector<int>& nums);
        /// KSum通用递归解法，复杂度O(N^(k-1))
        static vector<vector<int>> KSum(vector<int>& nums, int k, int target);
    private:
        static vector<vector<int>> KSumHelper(vector<int>& nums, int k, int target, int left);
    };
}