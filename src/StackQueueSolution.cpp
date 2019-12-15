#include "StackQueueSolution.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

namespace Phoenix
{
    void StackQueueSolution::RunTestCase(StackQueueSolutionEnum type)
    {
        switch (type)
        {
        case StackQueueSolutionEnum::ValidParentheses:
        {
            string s = "(((s[]w))2)";
            string result = isValidParenthese(s) ? ("match") : ("not match");
            cout << s << " is " << result << endl;
            break;
        }
        case StackQueueSolutionEnum::BackspaceCompare:
        {
            string s = "#a#b";
            string t = "a##b";
            string result = backspaceCompare(s, t) ? ("match") : ("not match");
            string output = "s=" + s + "\nt=" + t + "\n" + result;
            cout << output << endl;
            break;
        }
        case StackQueueSolutionEnum::KthLagest:
        {
            vector<int> nums = {8,7,1,9,0,3};
            KthLargest largest(5, nums);
            cout << largest.add(10) << endl;
            cout << largest.add(3) << endl;
            cout << largest.add(10) << endl;
            cout << largest.add(10) << endl;
            cout << largest.add(10) << endl;
            break;
        }
        case StackQueueSolutionEnum::MaxSlidingWindow:
        {
            vector<int> nums = {1,3,-1,-3,5,3,6,7};
            auto res = KthLargest::maxSlidingWindow(nums, 3);
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i] << ", ";
            }
            cout << endl;
            break;
        }
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

    KthLargest::KthLargest(int k, vector<int>& nums)
    {
        _k = k;
        for (int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }

    int KthLargest::add(int val)
    {
        if (_priQueue.size() < _k)
        {
            _priQueue.push(val);
        }
        else
        {
            if (_priQueue.top() < val)
            {
                _priQueue.pop();
                _priQueue.push(val);
            }
        }
        return _priQueue.top();
    }

    int KthLargest::findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int> > _priQueue;
        int val = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            val = nums[i];
            if (_priQueue.size() < k)
            {
                _priQueue.push(val);
            }
            else
            {
                if (_priQueue.top() < val)
                {
                    _priQueue.pop();
                    _priQueue.push(val);
                }
            }
        }
        return _priQueue.top();
    }
    
    vector<int> KthLargest::maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        // 双端队列辅助
        deque<int> helperDeque;
        // 插入元素时，队尾比插入元素小的要出列，留下的队首元素就是sliding K里面的最大值
        // 由于双端队列里面的元素个数不固定，为了确保k窗口，队列里面需要记录的是数组元素下标
        int val;
        
        // 开始滑动窗口，注意helperDeque里面保存的是下标，方便计算是否该出队列了
        for (int i = 0; i < nums.size(); i++)
        {
            val = nums[i];
            // 当元素个数超过k个时就要考虑出队列的问题了
            if (i >= k && helperDeque.front() <= i - k)
            {
                helperDeque.pop_front();
            }
            // 进入新元素的时候，要从队尾出列小于新元素的元素
            while (!helperDeque.empty() && nums[helperDeque.back()] <= val)
            {
                helperDeque.pop_back();
            }
            helperDeque.push_back(i);
            // 下标从0开始，那么从第k-1个元素处理完毕就要开始记录结果数组了
            if (i >= k-1)
            {
                res.push_back(nums[helperDeque.front()]);
            }
        }
        return res;
    }

} // namespace Phoenix
