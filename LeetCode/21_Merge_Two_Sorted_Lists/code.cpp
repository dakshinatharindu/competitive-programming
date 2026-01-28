#include <iostream>
#include <vector>
#include <string>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* last = &dummy;

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                last->next = list2;
                break;
            } else if (list2 == nullptr) {
                last->next = list1;
                break;
            } else {
                if (list1->val < list2->val) {
                    last->next = list1;
                    list1 = list1->next;
                } else {
                    last->next = list2;
                    list2 = list2->next;
                }
                last = last->next;
            }
        }

        return dummy.next;
    }
};

int main() {
    Solution solution;

    // Create first sorted linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge the two lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged linked list
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}