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

        if(head->next == nullptr || head->next->next == nullptr) return;

        vector<ListNode*> idx;

        ListNode* cur = head;

        while(cur != nullptr){
            idx.push_back(cur);
            cur = cur->next;
        }

        ListNode* prev = idx[0];
        ListNode* exch = new ListNode();
        int n = idx.size();

        for(int i = 1; i <= (n/2); i++){
            cur = idx[i];
            exch = idx[n-i];
            prev->next = exch;
            exch->next = cur;

            prev = cur; 
        }

        prev->next = nullptr;

        return;

    }
};
