#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverse(ListNode* head, int k, ListNode*& tail) {
        ListNode* rev_head;
        ListNode* prev;
        ListNode* next;
        for (int i = 0; i < k; i++) {
            next = head->next;
            rev_head = head;
            if (i != 0) {
                rev_head->next = prev;
            } else {
                tail = rev_head;
            }
            prev = rev_head;
            head = next;
        }
        tail->next = head;

        return rev_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode* curr = head;
        ListNode* curr_point = head;
        ListNode* rev_head = head;
        ListNode* tail;
        ListNode* prev_tail;
        bool is_first = true;
        while (true) {
            for (int i = 0; i < k; i++) {
                if (curr == nullptr) {
                    return rev_head;
                }
                curr = curr->next;
            }

            if (is_first) {
                rev_head = reverse(curr_point, k, tail);
                is_first = false;
            } else {
                prev_tail = tail;
                ListNode* tmpHead = reverse(curr_point, k, tail);
                prev_tail->next = tmpHead;
            }
            curr_point = curr;
        }

        return rev_head;
    }
};

int main() {
    Solution solution;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = solution.reverseKGroup(head, k);

    cout << "Reversed linked list in groups of " << k << ":\n";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}