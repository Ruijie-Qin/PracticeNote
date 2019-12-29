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
}