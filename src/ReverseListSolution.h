
#include <cstddef>

namespace Phoenix
{
	/* Definition for singly-linked list.*/
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	enum LinkListSolutionEnum
	{
		ReverseList = 1,
		SwapPairsList,
		HasCycle,
		CheckCycle,
		SwapPairsListKGroup,
	};

	class LinkListSolution
	{
	public:
		/// 执行测试案例
		void RunTestCase(LinkListSolutionEnum solutionType = LinkListSolutionEnum::ReverseList);
		/// 执行反转和交换测试案例
		void RunReverseListTestCase(LinkListSolutionEnum solutionType = LinkListSolutionEnum::ReverseList);
		/// 执行是否有环的测试案例
		void RunHasCycleListTestCase(LinkListSolutionEnum solutionType = LinkListSolutionEnum::HasCycle);
		/// 反转链表, leetcode: Reverse Linked List
		ListNode* reverseList(ListNode* head);
		/// 交换连续两个节点, leetcode: Swap Nodes in Pairs
		ListNode* swapPairs(ListNode* head);
		/// k个节点逆序: Reverse Nodes in k-Group
		ListNode* reverseKGroup(ListNode* head, int k);
		/// 判断链表是否有环, leetcode: Linked List Cycle
		bool hasCycle(ListNode* head);
		/// 找到环的起始点:  Linked List Cycle II
		ListNode *detectCycle(ListNode *head);
	private:
		/// 删除链表
		void deleteList(ListNode* head);
	};
}