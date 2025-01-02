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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr){
            return head;
        }

        ListNode* currentNode = head;

        while (currentNode->next != nullptr){
            ListNode* nextNode = currentNode->next;
            int val1 = currentNode->val;
            int val2 = nextNode->val;

            // Start with the lower value as the divisor, as GCD cannot be greater than it
            int divisor = val1 < val2 ? val2 : val1;

            while (val1 % divisor != 0 || val2 % divisor != 0){
                divisor -= 1;
            }

            ListNode* newNode = new ListNode(divisor, nextNode);
            currentNode->next = newNode;

            currentNode = nextNode;
        }
        
        return head;
    }
};