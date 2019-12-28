
namespace Phoenix
{
    enum SearchSolutionEnum
    {
        SS1 = 1,
    };

    class SearchSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(SearchSolutionEnum solutionType = SearchSolutionEnum::SS1);
    };
}