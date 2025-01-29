/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // Do the fast and slow pointers
        ListNode* fast = head;
        ListNode* slow = head;
        // cout << "fast: " << fast->val << '\n';
        // cout << "slow: " << slow->val << '\n';

        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            // cout << "Fast: " << fast->val << '\n';
            // cout << "Slow: " << slow->val << "\n\n";
        }

        if (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // cout << "Fast: " << fast->val << '\n';
        // cout << "Slow: " << slow->val << "\n\n";

        // Loop until the head = the slow pointer, in which case point it to nil and return the original head
        ListNode* nextNode = nullptr;
        // cout << "Head: " << head->val << '\n';

        while (head != slow){
            // Save the head's next node
            nextNode = head->next;
            // cout << "Next: " << nextNode->val << '\n';

            // Travel down the slow pointer to the end
            ListNode* endNode = slow;
            ListNode* beforeEnd = slow;
            while (endNode->next != nullptr){
                beforeEnd = endNode;
                endNode = endNode->next;
            }

            // cout << "End: " << endNode->val << '\n';
            // cout << "beforeEnd: " << beforeEnd->val << '\n';
            // Cut off the end node from the list
            beforeEnd->next = nullptr;

            // Point the head to the slow pointer's end ndoe
            head->next = endNode;

            // Point the end node to the saved next node, unless the end node and next node are equal
            if (endNode != nextNode){
                endNode->next = nextNode;
            }

            // Make the head the saved next node
            head = nextNode;

            // cout << "Head: " << head->val << "\n\n";
        }

        // Loop until the head = the slow pointer, in which case point it to nil and return the original head
        head->next = nullptr;
    }
};