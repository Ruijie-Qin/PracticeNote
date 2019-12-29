#include <vector>
#include <string>
using namespace std;

namespace Phoenix
{
    enum SearchSolutionEnum
    {
        GenParentheses = 1,
    };

    class SearchSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(SearchSolutionEnum solutionType = SearchSolutionEnum::GenParentheses);
        /// 22. Generate Parentheses
        vector<string> generateParenthesis(int n);
    private:
        void GenParenthesisHelper(vector<string> &result, int n, int leftUsed, int rightUsed, string currentResult);
    };
}