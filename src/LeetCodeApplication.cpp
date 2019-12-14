// LeetCodeApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ReverseListSolution.h"
#include "StackQueueSolution.h"
#include <iostream>

using namespace std;
using namespace Phoenix;

int main()
{
    cout << "Hello World!\n"; 
#pragma region 链表题目
	// LinkListSolution reverseTest;
	// reverseTest.RunTestCase(LinkListSolutionEnum::SwapPairsListKGroup);
#pragma endregion

#pragma region 栈和队列
	StackQueueSolution sqSolution;
	sqSolution.RunTestCase(StackQueueSolutionEnum::ValidParentheses);
#pragma endregion

	return 0;
}
