#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	ListNode* insertionSortList(ListNode* head)
	{
		auto ans = new ListNode(0);
		ans->next = head;
		
		auto cur = head;
		auto precur = ans;
		auto p = head;
		auto pre = ans;
		auto end = ans;

		while (cur)
		{
			p = ans->next;


			if (p->next == nullptr)
			{
				cur = cur->next;
				break;
			}
			if (p->val <= cur->val && p->next->val > cur->val)
			{
				break;
			}
				


			while (cur->val > p->val && p != cur)
			{
				pre = p;
				p = p->next;
			}
			if (cur == p)
			{
				precur = cur;
				cur = cur->next;
				continue;
			}

			auto tmp = precur;
			precur->next = cur->next;
			pre->next = cur;
			cur->next = p;
			
			precur = tmp->next;
			cur = p->next;


			end->next = cur->next;
		}

		return ans->next;
	}
};

int main()
{
	auto p1 = new ListNode(4);
	auto p2 = new ListNode(2);
	auto p3 = new ListNode(1);
	auto p4 = new ListNode(3);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	Solution res;
	auto ans = res.insertionSortList(p1);

	return 0;
}