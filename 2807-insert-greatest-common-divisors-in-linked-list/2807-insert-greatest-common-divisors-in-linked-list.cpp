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
            int val1 = currentNode->val;
            int val2 = nextNode->val;

            while (val2 != 0){
                int temp = val2;
                val2 = val1 % val2;
                val1 = temp;
            }

            currentNode->next = new ListNode(val1, nextNode);
            currentNode = nextNode;
        }

        return head;
    }
};