#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    static ListNode* getList(vector<int> list) {
        ListNode* last = nullptr;
        for (int i = list.size() - 1; i >= 0; --i) {
            ListNode* current = new ListNode(list[i], last);
            last = current;
        }
        return last;
    }
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int counter = 0;

        if (left == right) {
            return head;
        }
        ListNode* leftNode = nullptr;
        ListNode* last = nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;
        bool reversing = false;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            if (counter == left) {
                reversing = true;
                leftNode = current;
            }
            if (reversing) {
                current->next = last;
            }
            if (counter == right) {
                reversing = false;
                leftNode->next->next = current;
                leftNode->next = next;
                break;
            }
            last = current;
            current = next;
            counter++;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode* head = ListNode::getList({3, 5});
    auto res = sol.reverseBetween(head, 1, 2);
}