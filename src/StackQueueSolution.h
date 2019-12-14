#include <string>
#include <stack>
#include <queue>
using namespace std;

enum StackQueueSolutionEnum
{
    ValidParentheses = 1,
    BackspaceCompare,
};

class StackQueueSolution {
public:
    /// 执行测试案例
	void RunTestCase(StackQueueSolutionEnum solutionType = StackQueueSolutionEnum::ValidParentheses);
    /// 括号配对, leetcode: Valid Parentheses
    bool isValidParenthese(string s);
    /// leetcode: Backspace String Compare
    bool backspaceCompare(string S, string T);
private:
    /// 帮助backspaceCompare预处理得到结果堆栈
    void backspacePreProcess(string S, stack<char> &sStack);
};

/// leetcode: Implement Queue using Stacks
class MyQueueByStack {
public:
    /** Initialize your data structure here. */
    MyQueueByStack();
    
    /** Push element x to the back of queue. */
    void push(int x);
    
    /** Removes the element from in front of queue and returns that element. */
    int pop();
    
    /** Get the front element. */
    int peek();
    
    /** Returns whether the queue is empty. */
    bool empty();
private:
    stack<int> inputStack;
    stack<int> outputStack;
};

/// leetcode: Implement Stack using Queues
class MyStackByQueue {
public:
    /** Initialize your data structure here. */
    MyStackByQueue();

    /** Push element x onto stack. */
    void push(int x);
    
    /** Removes the element on top of the stack and returns that element. */
    int pop();
    
    /** Get the top element. */
    int top();
    
    /** Returns whether the stack is empty. */
    bool empty();
private:
    queue<int> firstQueue;
    queue<int> secondQueue;
};