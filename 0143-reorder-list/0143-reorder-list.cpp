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

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Loop until the head = the slow pointer, in which case point it to nil and return the original head
        ListNode* nextNode = nullptr;

        while (head != slow){
            // Save the head's next node
            nextNode = head->next;

            // Travel down the slow pointer to the end
            ListNode* endNode = slow;
            ListNode* beforeEnd = slow;
            while (endNode->next != nullptr){
                beforeEnd = endNode;
                endNode = endNode->next;
            }

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
        }

        // Loop until the head = the slow pointer, in which case point it to nil and return the original head
        head->next = nullptr;
    }
};