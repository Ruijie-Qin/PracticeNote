#include "ReverseListSolution.h"

#include <iostream>

using namespace std;

namespace Phoenix
{
/// 删除链表
void LinkListSolution::deleteList(ListNode *head)
{
	ListNode *curNode = head;
	while (curNode)
	{
		ListNode *tmp = curNode;
		curNode = curNode->next;
		tmp->next = NULL;
		delete tmp;
	}
	head = NULL;
}
/// 执行各种测试案例
void LinkListSolution::RunTestCase(LinkListSolutionEnum solutionType)
{
	switch (solutionType)
	{
	case ReverseList:
	case SwapPairsList:
	case SwapPairsListKGroup:
		RunReverseListTestCase(solutionType);
		break;
	case HasCycle:
	case CheckCycle:
		RunHasCycleListTestCase(solutionType);
		break;
	default:
		break;
	}
}
/// 执行有环的测试案例
void LinkListSolution::RunHasCycleListTestCase(LinkListSolutionEnum solutionType)
{
	ListNode *head = new ListNode(0);
	ListNode *curNode = head;
	ListNode *entryPoint = NULL;
	for (int i = 1; i <= 4; i++)
	{
		if (i == 4)
		{
			entryPoint = curNode;
		}
		curNode->next = new ListNode(i);
		curNode = curNode->next;
	}
	curNode->next = entryPoint;
	switch (solutionType)
	{
	case HasCycle:
	{
		bool _hasCycle = hasCycle(head);
		cout << _hasCycle << endl;
		break;
	}
	case CheckCycle:
	{
		ListNode *entryPt = detectCycle(head);
		if (entryPt)
		{
			cout << "entryPt=" << entryPt->val << endl;
		}
		else
		{
			cout << "no cycle" << endl;
		}
		break;
	}
	default:
		break;
	}
}

/// 执行测试案例
void LinkListSolution::RunReverseListTestCase(LinkListSolutionEnum solutionType)
{
	ListNode *head = new ListNode(0);
	ListNode *curNode = head;
	// 创建链表
	for (int i = 1; i <= 0; i++)
	{
		curNode->next = new ListNode(i);
		curNode = curNode->next;
	}
	// 输出链表
	curNode = head;
	while (curNode)
	{
		cout << curNode->val << ",";
		curNode = curNode->next;
	}
	cout << endl;
	// 处理链表
	switch (solutionType)
	{
	case ReverseList:
		head = reverseList(head);
		break;
	case SwapPairsList:
		head = swapPairs(head);
		break;
	case SwapPairsListKGroup:
		head = reverseKGroup(head, 1);
		break;
	default:
		head = NULL;
		break;
	}
	// 输出处理后的链表
	curNode = head;
	while (curNode)
	{
		cout << curNode->val << ",";
		curNode = curNode->next;
	}
	cout << endl;
	// 删除链表
	deleteList(head);
}

/// 反转链表
ListNode *LinkListSolution::reverseList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *preNode = NULL;
	ListNode *curNode = head;
	while (curNode)
	{
		ListNode *tmp = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = tmp;
	}
	head = preNode;
	return head;
}

/// 交换连续两个节点
ListNode *LinkListSolution::swapPairs(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *realHead = new ListNode(0);
	realHead->next = head;

	ListNode *firstNode = head;
	ListNode *secondNode = head->next;
	ListNode *preFirst = realHead;
	while (firstNode && secondNode)
	{
		firstNode->next = secondNode->next;
		secondNode->next = firstNode;
		preFirst->next = secondNode;
		preFirst = firstNode;
		// 移动到下一组节点
		firstNode = firstNode->next;
		if (firstNode != NULL)
		{
			secondNode = firstNode->next;
		}
	}
	return realHead->next;
}

ListNode *LinkListSolution::reverseKGroup(ListNode *head, int k)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *realHead = new ListNode(0);
	realHead->next = head;

	ListNode *preNode = realHead;
	ListNode *firstNode = head;
	ListNode *secondNode = head->next;
	ListNode *tmp = NULL;
	while (firstNode && secondNode)
	{
		// check left list length
		int i = k;
		tmp = firstNode;
		while (tmp && i-- > 0)
		{
			tmp = tmp->next;
		}
		// 如果长度不够, 就可以直接返回了
		if (i > 0)
		{
			break;
		}
		for (int i = 0; i < k - 1; i++)
		{
			tmp = secondNode->next;
			secondNode->next = preNode->next;
			firstNode->next = tmp;
			preNode->next = secondNode;

			secondNode = firstNode->next;
		}
		preNode = firstNode;

		firstNode = firstNode->next;
		if (firstNode)
		{
			secondNode = firstNode->next;
		}
	}
	return realHead->next;
}

/// 使用快慢指针判断是否有环
bool LinkListSolution::hasCycle(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

ListNode *LinkListSolution::detectCycle(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	ListNode *firstMeet = NULL;
	// 寻找相遇点
	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			firstMeet = slow;
			break;
		}
	}
	// 如果没有相遇, 则返回空
	if (firstMeet == NULL)
	{
		return NULL;
	}
	// // 从头节点和相遇节点开始+1, 第一次相遇点就是入口
	slow = head;
	while (slow && firstMeet)
	{
		if (slow == firstMeet)
		{
			return slow;
		}
		slow = slow->next;
		firstMeet = firstMeet->next;
	}
	return NULL;
}
} // namespace Phoenix
