#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* anchor = head;
        ListNode* prev = dummy;
        bool      death = false;
        while (anchor) {
            if (!anchor->next || anchor->next->val != anchor->val) {
                if (death) {
                    prev->next = anchor->next;
                    death = false;
                } else {
                    prev = anchor;
                }
                anchor = anchor->next;
            } else {
                anchor->next = anchor->next->next;
                death = true;
            }
        }
        return dummy->next;
    }
};

ListNode* makeList(vector<int> nums)
{
    ListNode* dummy = new ListNode();
    ListNode* anchor = dummy;
    for (auto& i : nums) {
        anchor->next = new ListNode(i);
        anchor = anchor->next;
    }
    return dummy->next;
}

void outList(ListNode* head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Solution sol;
    auto*    head = makeList({1, 1});
    auto*    res = sol.deleteDuplicates(head);
    outList(res);
}