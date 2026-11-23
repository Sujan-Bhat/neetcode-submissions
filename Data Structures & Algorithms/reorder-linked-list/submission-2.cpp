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
        vector<ListNode*> arrayList;
        ListNode* cur = head;

        while(cur != nullptr){
            arrayList.push_back(cur);
            cur = cur->next;
        }

        if(arrayList.size() <= 2){
            return;
        }
        cur = head;
        int i = 1;
        int j = arrayList.size() - 1;

        while(i <= j){
            cur->next = arrayList[j];
            cur = cur->next;
            cur->next = arrayList[i];
            cur = cur->next;
            i++;
            j--;
        }
        cur->next = nullptr;
        return;
    }
};
