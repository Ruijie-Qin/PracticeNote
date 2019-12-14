#include "StackQueueSolution.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void StackQueueSolution::RunTestCase(StackQueueSolutionEnum type)
{
    switch(type)
    {
    case StackQueueSolutionEnum::ValidParentheses:
        {
            string s = "(((s[]w))2)";
            string result = isValidParenthese(s) ? ("match") : ("not match");
            cout << s << " is " << result << endl;
        }
        break;
    default:
        break;
    }
}

bool StackQueueSolution::isValidParenthese(string s)
{
    map<char, char> charMap = {
        {'}', '{'}, {']', '['}, {')', '('}
    };
    set<char> charSet = {'{', '[', '('};
    stack<char> charStack;
    char curChar = ' ';
    for(int i = 0; i < s.length(); i++)
    {
        curChar = s[i];
        // 如果是可用符号就入栈
        if (charSet.find(curChar) != charSet.end())
        {
            charStack.push(curChar);
            continue;
        }
        // 如果不是可用符号, 但是是配对符号, 那么要去栈里面判断下了
        if (charMap.find(curChar) != charMap.end())
        {
            char matchChar = charMap[curChar];
            if (!charStack.empty() && charStack.top() == matchChar)
            {
                charStack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return charStack.empty();
}