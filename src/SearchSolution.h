#include <vector>
#include <string>
#include <set>
#include <string>
using namespace std;

namespace Phoenix
{
    enum SearchSolutionEnum
    {
        GenParentheses = 1,
        NQueen,
        NQueen2,
    };

    class SearchSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(SearchSolutionEnum solutionType = SearchSolutionEnum::GenParentheses);
        /// 22. Generate Parentheses
        vector<string> generateParenthesis(int n);
        /// 51. N-Queens
        vector<vector<string>> solveNQueens(int n);
        /// 52. N-Queens II
        int totalNQueens(int n);
    private:
        void GenParenthesisHelper(vector<string> &result, int n, int leftUsed, int rightUsed, string currentResult);

        // 不可放子的位置(左右斜线+列)
        set<int> NQueensLeftSet;
        set<int> NQueensRightSet;
        set<int> NQueensColSet;
        vector<vector<string>> ConvertToNQueenResult(vector<vector<int>> preResult, int n);
        /// 使用set
        void NQueenSearchHelp(vector<vector<int>> &result, vector<int> curResult, int row, int n);
        unsigned long NQueen2TotalCount;
        /// 使用bitMask,最多支持n=63
        void NQueen2SearchHelp(int n, int row, unsigned long left, unsigned long right, unsigned long col);
    };
}