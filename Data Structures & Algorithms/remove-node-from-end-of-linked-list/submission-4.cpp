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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* res = new ListNode(0, head);
        ListNode* bord = head;
        for (int i = 0; i < n; ++i){
            bord= bord->next;
        }

        ListNode* elim = res;

        while(bord) {
            bord = bord->next;
            elim = elim->next;
        }


        elim->next = elim->next->next;
        return res->next;



    }
};
