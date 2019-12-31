#include "SearchSolution.h"

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
            }
            break;
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
            }
            break;
        case SearchSolutionEnum::NQueen2:
            {
                cout << totalNQueens(4) << endl;
                cout << totalNQueens(3) << endl;
                cout << totalNQueens(5) << endl;
                cout << totalNQueens(16) << endl;
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
            if (NQueensLeftSet.find(i+row) != NQueensLeftSet.end() || NQueensRightSet.find(i-row) != NQueensRightSet.end() || NQueensColSet.find(i) != NQueensColSet.end())
            {
                continue;
            }
            curResult.push_back(i);
            NQueensLeftSet.insert(i+row);
            NQueensRightSet.insert(i-row);
            NQueensColSet.insert(i);

            NQueenSearchHelp(result, curResult, row+1, n);

            curResult.pop_back();
            NQueensLeftSet.erase(i+row);
            NQueensRightSet.erase(i-row);
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
            bits = bits & (bits-1);
        }
    }
}