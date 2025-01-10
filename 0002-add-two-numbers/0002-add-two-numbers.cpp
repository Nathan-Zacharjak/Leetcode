#include <print>
typedef long long ll;
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
    ListNode * helper(ListNode* l1, ListNode* l2, ListNode* head, ListNode* lastNode, int carry){
        if (l1 == nullptr && l2 == nullptr && carry == 0){
            return head;
        }

        int i1 = 0;
        if (l1 != nullptr){
            i1 = l1->val;
            l1 = l1->next;
        }
        int i2 = 0;
        if (l2 != nullptr){
            i2 = l2->val;
            l2 = l2->next;
        }
        int sum = i1 + i2 + carry;
        carry = sum / 10;

        ListNode * newNode = new ListNode(sum % 10);
        if (head == nullptr){
            head = newNode;
        } else {
            lastNode->next = newNode;
        }

        lastNode = newNode;
        return helper(l1, l2, head, lastNode, carry);
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, nullptr, nullptr, 0);

        // // While loop both lists at the same time
        // ll i1 = 0;
        // ll i2 = 0;
        // ll powerOfTen = 1;

        // while (l1 != nullptr || l2 != nullptr){
        //     // If one has ended, ignore it
        //     if (l1 != nullptr){
        //         // Else construct the next digit by timesing by 10 and adding the digit
        //         i1 += l1->val * powerOfTen;
        //         l1 = l1->next;
        //     }
        //     if (l2 != nullptr){
        //         i2 += l2->val * powerOfTen;
        //         l2 = l2->next;
        //     }

        //     powerOfTen *= 10;
        // }

        // // Once both lists are traversed, get the sum
        // ll sum = i1 + i2;
        // println("Sum: {}", sum);
        // // Create nullptr head and lastNode variables
        // ListNode * head = nullptr;
        // ListNode * lastNode = nullptr;

        // // Do-While loop until the sum is 0
        // do {
        //     // Mod the sum by 10 to get the next digit
        //     int nextDigit = sum % 10;
        //     // Create a node to put the digit into
        //     ListNode * nextNode = new ListNode(nextDigit);

        //     // If the head is null, make the node equal to the head, else link the lastNode to the nextNode
        //     if (head == nullptr){
        //         head = nextNode;
        //     } else {
        //         lastNode->next = nextNode;
        //     }

        //     // Make the lastNode = nextNode
        //     lastNode = nextNode;
        //     // Divide the sum by 10 and continue the loop
        //     sum /= 10;
        // } while (sum != 0);

        // // Return the head
        // return head;
    }
};