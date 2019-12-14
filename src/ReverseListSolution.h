
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

	enum SolutionEnum
	{
		ReverseList = 1,
		SwapPairsList,
		HasCycle,
	};

	class LinkListSolution
	{
	public:
		/// 执行测试案例
		void RunTestCase(SolutionEnum solutionType = SolutionEnum::ReverseList);
		/// 执行反转和交换测试案例
		void RunReverseListTestCase(SolutionEnum solutionType = SolutionEnum::ReverseList);
		/// 执行是否有环的测试案例
		void RunHasCycleListTestCase();
		/// 反转链表, leetcode: Reverse Linked List
		ListNode* reverseList(ListNode* head);
		/// 交换连续两个节点, leetcode: Swap Nodes in Pairs
		ListNode* swapPairs(ListNode* head);
		/// 判断链表是否有环, leetcode: Linked List Cycle
		bool hasCycle(ListNode* head);
	private:
		/// 删除链表
		void deleteList(ListNode* head);
	};
}