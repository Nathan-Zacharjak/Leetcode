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
        ListNode * currentNode = head;

        while (currentNode->next != nullptr){
            ListNode * nextNode = currentNode->next;

            currentNode->next = new ListNode(gcd(currentNode->val, nextNode->val), nextNode);
            
            currentNode = nextNode;
        }

        return head;
    }
};