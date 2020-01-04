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
        ValidSudoki,
        SolveSudoki,
    };

    struct SudokuCandidate
    {
        int row;
        int col;
        set<char> candidateSet;
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
        /// 36. Valid Sudoku
        bool isValidSudoku(vector<vector<char>>& board);
        /// 37. Sudoku Solver
        void solveSudoku(vector<vector<char>>& board);
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
        /// 数独Valid校验Helper, 在row和col的位置字符c是否有效
        bool isValidSudokuHelper(vector<vector<char>> &board, int row, int col, char c);
        /// 数独求解所需的辅助方法和变量
        int rowFill[9][10]; // rowFill[i][j]的值表示第i行是否有元素
        int colFill[9][10];
        int subBoxFill[9][10];
        bool isSolvedSudoku;
        bool canPlace(int row, int col, int c);
        void placeNum(int row, int col, int num, bool isPlace);
        void solveSudokuHelper(vector<vector<char>>& board, int row, int col);
        void placeNextNum(vector<vector<char>>& board, int row, int col);
    };
}