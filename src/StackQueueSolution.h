#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

namespace Phoenix
{
    enum StackQueueSolutionEnum
    {
        ValidParentheses = 1,
        BackspaceCompare,
        KthLagest,
        MaxSlidingWindow,
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

    /// 流式数据中的第K大元素: Kth Largest Element in a Stream
    class KthLargest 
    {
    public:
        KthLargest(int k, vector<int>& nums);
        int add(int val);
        // Kth Largest Element in an Array
        static int findKthLargest(vector<int>& nums, int k);
        /// Sliding Window Maximum
        static vector<int> maxSlidingWindow(vector<int>& nums, int k);
    private:
        priority_queue<int, vector<int>, greater<int> > _priQueue;
        int _k;
    };
}
