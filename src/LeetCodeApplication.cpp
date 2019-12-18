// LeetCodeApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ReverseListSolution.h"
#include "StackQueueSolution.h"
#include "MapSetSolution.h"
#include "TreeGraphSolution.h"
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
	// StackQueueSolution sqSolution;
	// sqSolution.RunTestCase(StackQueueSolutionEnum::MaxSlidingWindow);
#pragma endregion

#pragma region Map和Set
	// MapSetSolution msSolution;
	// msSolution.RunTestCase(MapSetSolutionEnum::KSum);
#pragma endregion

#pragma region Tree和Graph
	TreeSolution treeSolution;
	treeSolution.RunTestCase(TreeGraphSolutionEnum::NormalLowestComAc);
#pragma endregion

	return 0;
}
