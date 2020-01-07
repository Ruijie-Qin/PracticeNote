#include <vector>
using namespace std;

namespace Phoenix
{
    enum DPSolutionEnum
    {
        ClimbingStairs = 1,
    };

    class DPSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(DPSolutionEnum solutionType = DPSolutionEnum::ClimbingStairs);
        /// 70. Climbing Stairs
        int climbStairs(int n);
    };
}