#include "SearchSolution.h"
#include <algorithm>
#include <iostream>
using namespace std;
namespace Phoenix
{
void SearchSolution::RunTestCase(SearchSolutionEnum solutionType)
{
    switch (solutionType)
    {
    case SearchSolutionEnum::GenParentheses:
    {
        auto result = generateParenthesis(3);
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
        break;
    }
    case SearchSolutionEnum::NQueen:
    {
        auto result = solveNQueens(4);
        cout << "[" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << "[" << endl;
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << "," << endl;
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
        break;
    }
    case SearchSolutionEnum::NQueen2:
    {
        cout << totalNQueens(4) << endl;
        cout << totalNQueens(3) << endl;
        cout << totalNQueens(5) << endl;
        cout << totalNQueens(16) << endl;
        break;
    }
    case SearchSolutionEnum::ValidSudoki:
    {
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        cout << isValidSudoku(board) << endl;
        break;
    }
    case SearchSolutionEnum::SolveSudoki:
    {
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        vector<vector<char>> board1 = {
            {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
            {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
            {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
            {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
            {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
            {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
            {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
        auto test = board;
        solveSudoku(test);
        for (int i = 0; i < test.size(); i++)
        {
            string line = "";
            for (int j = 0; j < test[i].size(); j++)
            {
                line = line + test[i][j] + ",";
            }
            cout << line << endl;
        }
        break;
    }
    case SearchSolutionEnum::mysqrt:
    {
        double x = 7;
        cout << mySqrtHelper(x, 1e-10) << endl;
        cout << mySqrt(x) << endl;
        break;
    }
    case SearchSolutionEnum::friendCircleNum:
    {
        vector<vector<int>> M = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}};
        cout << findCircleNum(M) << endl;
        break;
    }
    default:
        break;
    }
}

vector<string> SearchSolution::generateParenthesis(int n)
{
    vector<string> result;
    GenParenthesisHelper(result, n, 0, 0, "");
    return result;
}

void SearchSolution::GenParenthesisHelper(vector<string> &result, int n, int leftUsed, int rightUsed, string currentResult)
{
    // 所有括号都用完了就可以终止递归了
    if (leftUsed == n && rightUsed == n)
    {
        result.push_back(currentResult);
        return;
    }

    if (leftUsed < n)
    {
        GenParenthesisHelper(result, n, leftUsed + 1, rightUsed, currentResult + '(');
    }
    // 剪枝，右边比左边少才能继续加右括号
    if (rightUsed < leftUsed)
    {
        GenParenthesisHelper(result, n, leftUsed, rightUsed + 1, currentResult + ')');
    }
}

vector<vector<string>> SearchSolution::solveNQueens(int n)
{
    vector<vector<int>> result;
    vector<int> curResult;
    NQueenSearchHelp(result, curResult, 0, n);
    return ConvertToNQueenResult(result, n);
}

int SearchSolution::totalNQueens(int n)
{
    if (n < 1)
    {
        return 0;
    }
    NQueen2TotalCount = 0;
    NQueen2SearchHelp(n, 0, 0, 0, 0);
    return NQueen2TotalCount;
}

vector<vector<string>> SearchSolution::ConvertToNQueenResult(vector<vector<int>> preResult, int n)
{
    vector<vector<string>> result;
    for (int i = 0; i < preResult.size(); i++)
    {
        vector<string> res;
        for (int j = 0; j < preResult[i].size(); j++)
        {
            string str;
            for (int k = 0; k < n; k++)
            {
                str += (preResult[i][j] == k ? 'Q' : '.');
            }
            res.push_back(str);
        }
        result.push_back(res);
    }
    return result;
}

void SearchSolution::NQueenSearchHelp(vector<vector<int>> &result, vector<int> curResult, int row, int n)
{
    // 遍历完N行就结束
    if (row >= n)
    {
        result.push_back(curResult);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // 剪枝
        if (NQueensLeftSet.find(i + row) != NQueensLeftSet.end() || NQueensRightSet.find(i - row) != NQueensRightSet.end() || NQueensColSet.find(i) != NQueensColSet.end())
        {
            continue;
        }
        curResult.push_back(i);
        NQueensLeftSet.insert(i + row);
        NQueensRightSet.insert(i - row);
        NQueensColSet.insert(i);

        NQueenSearchHelp(result, curResult, row + 1, n);

        curResult.pop_back();
        NQueensLeftSet.erase(i + row);
        NQueensRightSet.erase(i - row);
        NQueensColSet.erase(i);
    }
}

void SearchSolution::NQueen2SearchHelp(int n, int row, unsigned long left, unsigned long right, unsigned long col)
{
    // 遍历完N行就结束
    if (row >= n)
    {
        NQueen2TotalCount++;
        return;
    }
    unsigned long bits = (~(left | right | col) & ((1 << n) - 1));

    while (bits)
    {
        unsigned long p = bits & (-bits); // 从最低位的1开始遍历
        // 下一行的不可放置区域，左边要左移一位，右边要右移一位
        NQueen2SearchHelp(n, row + 1, (left | p) << 1, (right | p) >> 1, col | p);
        // 清零最右边的1, 做下一种情况的搜寻
        bits = bits & (bits - 1);
    }
}

bool SearchSolution::isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (isValidSudokuHelper(board, i, j, board[i][j]))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool SearchSolution::isValidSudokuHelper(vector<vector<char>> &board, int row, int col, char c)
{
    if (c == '.')
    {
        return true;
    }
    bool res = true;
    char stack = board[row][col];
    board[row][col] = '.'; // 先修改下这个格子的内容，下面比较的时候就不用考虑比较到自己了
    int subBoxRowIndex = (row / 3) * 3;
    int subBoxColIndex = (col / 3) * 3;
    for (int i = 0; i < 9; i++)
    {
        // 检测行和列
        if (board[row][i] == c || board[i][col] == c)
        {
            res = false;
            break;
        }
        // 找到row和col所属的subBox
        if (board[subBoxRowIndex + i / 3][subBoxColIndex + i % 3] == c)
        {
            res = false;
            break;
        }
    }
    board[row][col] = stack;
    return res;
}

void SearchSolution::solveSudoku(vector<vector<char>> &board)
{
    isSolvedSudoku = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            rowFill[i][j] = 0;
            colFill[i][j] = 0;
            subBoxFill[i][j] = 0;
        }
    }
    // 根据初始数据填充辅助数组
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            char c = board[i][j];
            if (c != '.')
            {
                placeNum(i, j, c - '0', true);
            }
        }
    }
    solveSudokuHelper(board, 0, 0);
}

void SearchSolution::placeNum(int row, int col, int num, bool isPlace)
{
    if (isPlace)
    {
        rowFill[row][num]++;
        colFill[col][num]++;
        subBoxFill[(row / 3) * 3 + col / 3][num]++;
    }
    else
    {
        rowFill[row][num]--;
        colFill[col][num]--;
        subBoxFill[(row / 3) * 3 + col / 3][num]--;
    }
}

bool SearchSolution::canPlace(int row, int col, int num)
{
    return ((rowFill[row][num] + colFill[col][num] + subBoxFill[(row / 3) * 3 + col / 3][num]) == 0);
}

void SearchSolution::placeNextNum(vector<vector<char>> &board, int row, int col)
{
    if (row == 8 && col == 8)
    {
        isSolvedSudoku = true;
        return;
    }

    if (col == 8)
    {
        solveSudokuHelper(board, row + 1, 0);
    }
    else
    {
        solveSudokuHelper(board, row, col + 1);
    }
}
void SearchSolution::solveSudokuHelper(vector<vector<char>> &board, int row, int col)
{
    if (board[row][col] == '.')
    {
        for (int i = 1; i < 10; i++)
        {
            if (canPlace(row, col, i))
            {
                placeNum(row, col, i, true);
                board[row][col] = i + '0';
                placeNextNum(board, row, col);
                if (!isSolvedSudoku)
                {
                    placeNum(row, col, i, false);
                    board[row][col] = '.';
                }
            }
        }
    }
    else
    {
        placeNextNum(board, row, col);
    }
}

int SearchSolution::mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    int result = (int)mySqrtHelper(x, 1e-9) + 1;
    cout << "res=" << result << endl;
    if (result > x / result)
    {
        return result - 1;
    }
    else
    {
        return result;
    }
}

double SearchSolution::mySqrtHelper(double x, double precise)
{
    double left = 0;
    double right = x;
    while (left < right && (right - left) > precise)
    {
        double mid = left + (right - left) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid < x / mid)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return (right + left) / 2;
}

int SearchSolution::numIslands(vector<vector<char>> &grid)
{
    if (grid.size() <= 0)
    {
        return 0;
    }
    set<int> numIslandsVisited;
    int row = grid.size();
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        int col = grid[i].size();
        for (int j = 0; j < col; j++)
        {
            // 如果是1且没有被访问过，则进行DFS
            if (grid[i][j] != '0' && numIslandsVisited.find(i * col + j) == numIslandsVisited.end())
            {
                // 用于标记访问数组，没次DFS会把联通的1都标记为已访问
                numIsLandsDFS(grid, i, j, row, col, numIslandsVisited);
                count++;
            }
        }
    }
    return count;
}

void SearchSolution::numIsLandsDFS(vector<vector<char>> &grid, int i, int j, int row, int col, set<int> &numIslandsVisited)
{
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0' || numIslandsVisited.find(i * col + j) != numIslandsVisited.end())
    {
        return;
    }
    numIslandsVisited.insert(i * col + j);
    int dfsX[4] = {-1, 1, 0, 0};
    int dfsY[4] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++)
    {
        numIsLandsDFS(grid, i + dfsX[k], j + dfsY[k], row, col, numIslandsVisited);
    }
}

/// 这里其实用一重循环就够了，本质问题是求一个无向图的有多少个连通分量
int SearchSolution::findCircleNum(vector<vector<int>> &M)
{
    if (M.size() <= 0)
    {
        return 0;
    }
    int row = M.size();
    int col = M[0].size();
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (M[i][j] == 1)
            {
                count++;
                // 把所有的找到过的朋友标记为0
                // cout << "begin" << endl;
                findCircleNumDFC(M, i, j, row, col);
                // cout << "end" << endl;
            }
        }
    }
    return count;
}

void SearchSolution::findCircleNumDFC(vector<vector<int>> &M, int i, int j, int row, int col)
{
    // cout << i << "," << j << endl;
    M[i][j] = 0;
    M[j][i] = 0;
    // 从j开始找到所有认识的朋友
    for (int k = 0; k < col; k++)
    {
        if (M[j][k] == 1)
        {
            findCircleNumDFC(M, j, k, row, col);
        }
    }
}

} // namespace Phoenix