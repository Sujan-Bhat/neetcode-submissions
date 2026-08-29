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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* prev = nullptr;
        int sum = 0, carry = 0;

        while(cur1 != nullptr && cur2 != nullptr){
            sum = (cur1->val + cur2->val) + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;

            cur2->val = sum;

            prev = cur2;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while(cur1 != nullptr){
            sum = cur1->val + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            prev->next = newNode;
            prev = prev->next;
            cur1 = cur1->next;
        }
        while(cur2 != nullptr){
            sum = cur2->val + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;

            cur2->val = sum;
            prev = cur2;
            cur2 = cur2->next;
        }

        if(carry > 0){
            ListNode* newNode = new ListNode(1);
            prev->next = newNode;
        }

        return l2;
        
    }
};
