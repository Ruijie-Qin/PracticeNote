#include <string>
using namespace std;

enum StackQueueSolutionEnum
{
    ValidParentheses = 1,

};

class StackQueueSolution {
public:
    /// 执行测试案例
	void RunTestCase(StackQueueSolutionEnum solutionType = StackQueueSolutionEnum::ValidParentheses);
    /// 括号配对, leetcode: Valid Parentheses
    bool isValidParenthese(string s);
};