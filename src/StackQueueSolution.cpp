#include "StackQueueSolution.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void StackQueueSolution::RunTestCase(StackQueueSolutionEnum type)
{
    switch (type)
    {
    case StackQueueSolutionEnum::ValidParentheses:
    {
        string s = "(((s[]w))2)";
        string result = isValidParenthese(s) ? ("match") : ("not match");
        cout << s << " is " << result << endl;
    }
    break;
    case StackQueueSolutionEnum::BackspaceCompare:
    {
        string s = "#a#b";
        string t = "a##b";
        string result = backspaceCompare(s, t) ? ("match") : ("not match");
        string output = "s=" + s + "\nt=" + t + "\n" + result;
        cout << output << endl;
    }
    break;
    default:
        break;
    }
}

bool StackQueueSolution::isValidParenthese(string s)
{
    map<char, char> charMap = {
        {'}', '{'}, {']', '['}, {')', '('}};
    set<char> charSet = {'{', '[', '('};
    stack<char> charStack;
    char curChar = ' ';
    for (int i = 0; i < s.length(); i++)
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

void StackQueueSolution::backspacePreProcess(string S, stack<char> &sStack)
{
    char tmp;
    for (int i = 0; i < S.length(); i++)
    {
        tmp = S[i];
        if (tmp != '#')
        {
            sStack.push(tmp);
            continue;
        }
        
        if (!sStack.empty())
        {
            sStack.pop();
        }
    }
}

bool StackQueueSolution::backspaceCompare(string S, string T)
{
    stack<char> sStack;
    stack<char> tStack;
    backspacePreProcess(S, sStack);
    backspacePreProcess(T, tStack);

    while (!sStack.empty() && !tStack.empty())
    {
        if (sStack.top() == tStack.top())
        {
            sStack.pop();
            tStack.pop();
        }
        else
        {
            return false;
        }
    }
    return sStack.empty() && tStack.empty();
}

MyQueueByStack::MyQueueByStack()
{
}

void MyQueueByStack::push(int x)
{
    inputStack.push(x);
}

int MyQueueByStack::pop()
{
    int peekVal = peek();
    outputStack.pop();
    return peekVal;
}

int MyQueueByStack::peek()
{
    if (outputStack.empty())
    {
        while (!inputStack.empty())
        {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }
    int peekVal = outputStack.top();
    return peekVal;
}

bool MyQueueByStack::empty()
{
    return (inputStack.empty() && outputStack.empty());
}

MyStackByQueue::MyStackByQueue()
{
}

void MyStackByQueue::push(int x)
{
    if (!firstQueue.empty())
    {
        secondQueue.push(x);
        while (!firstQueue.empty())
        {
            secondQueue.push(firstQueue.front());
            firstQueue.pop();
        }
    }
    else
    {
        firstQueue.push(x);
        while (!secondQueue.empty())
        {
            firstQueue.push(secondQueue.front());
            secondQueue.pop();
        }
    }
}

int MyStackByQueue::pop()
{
    int peekVal = top();
    if (!firstQueue.empty())
    {
        firstQueue.pop();
    }
    else
    {
        secondQueue.pop();
    }
    return peekVal;
}

int MyStackByQueue::top()
{
    if (!firstQueue.empty())
    {
        return firstQueue.front();
    }
    else
    {
        return secondQueue.front();
    }
}

bool MyStackByQueue::empty()
{
    return (firstQueue.empty() && secondQueue.empty());
}