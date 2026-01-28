#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* temp;
  
        while (head && head->next) {
            temp = head->next->next;
            prev->next = head->next;
            head->next->next = head;
            head->next = temp;

            prev = head;
            head = head->next;
        }

        return dummy.next;
    }
};

int main() {
    Solution s;

    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Swap pairs
    ListNode* swappedHead = s.swapPairs(head);

    // Print the swapped list
    while (swappedHead) {
        cout << swappedHead->val << " ";
        swappedHead = swappedHead->next;
    }
    cout << endl;

    return 0;
}