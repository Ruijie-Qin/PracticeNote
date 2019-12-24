
namespace Phoenix
{
    enum DivideConquerSolutionEnum
    {
        PowN = 1,
    };


    class DivideConquerSolution
    {
    public:
        /// 执行测试案例
		void RunTestCase(DivideConquerSolutionEnum solutionType = DivideConquerSolutionEnum::PowN);
        /// Pow(x, n)
        double myPow_1(double x, int n); // 递归
        double myPow_2(double x, int n); // 非递归
    };
}