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
        ListNode* resNode = new ListNode();
        ListNode* sumNode = resNode;

        int carry = 0;
        while(l1 || l2 || carry) {
            int v1 = 0, v2 = 0;
            if (l1){
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2){
                v2 = l2->val;
                l2 = l2->next;
            }
            int curSum = 0;
            curSum = v1 + v2 + carry;
            sumNode->next = new ListNode(curSum % 10);
            sumNode = sumNode->next;
            carry = curSum / 10;
        }
        return resNode->next;
    }
};
