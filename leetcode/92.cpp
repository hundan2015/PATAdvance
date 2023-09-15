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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* now = dummy;
        ListNode *leftNode, *prevNode;
        int       counter = 0;
        bool      isReversing = false;
        while (now != nullptr) {
            bool death = false;
            if (counter == left) {
                leftNode = now;
                isReversing = true;
            }

            if (counter == right) {
                leftNode->next->next = now;
                leftNode->next = now->next;
                death = true;
            }

            if (isReversing) {
                auto* temp = now->next;
                now->next = prevNode;
                prevNode = now;
                now = temp;
            } else {
                prevNode = now;
                now = now->next;
            }
            if (death)
                break;
            counter++;
        }

        return dummy->next;
    }
};

ListNode* makeListNode(vector<int> list)
{
    ListNode* next = nullptr;
    for (int i = list.size() - 1; i >= 0; --i) {
        ListNode* now = new ListNode(list[i], next);
        next = now;
    }
    return next;
}

int main()
{
    Solution sol;
    auto*    shit = makeListNode({5});
    auto*    res = sol.reverseBetween(shit, 2, 4);
    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
}