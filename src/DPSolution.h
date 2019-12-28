

namespace Phoenix
{
    enum DPSolutionEnum
    {
        DP1 = 1,
    };

    class DPSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(DPSolutionEnum solutionType = DPSolutionEnum::DP1);
    };
}