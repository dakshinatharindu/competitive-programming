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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* orig_head = head;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        head = orig_head;
        count -= n;

        if (count == 0) {
            return head->next;
        }

        while (count != 1) {
            head = head->next;
            count -= 1;
        }
        head->next = head->next->next;

        return orig_head;
    }
};

int main() {
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);

    
    
    // Print the modified list
    ListNode* current = s.removeNthFromEnd(head, 2);
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    std::cout << std::endl;
}