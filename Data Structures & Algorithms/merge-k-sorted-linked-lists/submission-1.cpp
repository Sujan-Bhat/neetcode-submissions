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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* ans = new ListNode();
        ListNode* cur = ans;

        while(c1 != nullptr && c2 != nullptr){
            if(c1->val < c2->val){
                cur->next = c1;
                c1 = c1->next;
            } else{
                cur->next = c2;
                c2 = c2->next;
            }
            cur = cur->next;
        }
        if(c1 != nullptr){
            cur->next = c1;
        }
        if(c2 != nullptr){
            cur->next = c2;
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;

        int totalSize = lists.size();
        int interval = 1;

        while(interval < totalSize){
            for(int i = 0; i < totalSize - interval; i += interval*2){
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};