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
        ListNode* tail = new ListNode(0);//assigns a tail to a new linked list
        ListNode* head = tail; //pointer to tail
        int carry=0;

        //checks if at tail of nodes
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1=l1->next; //changes to next node
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2->next;
            }
            carry = sum/10;
            head -> next = new ListNode(sum%10); //builds next node
            head = head->next;  //move to next node in pointer/tail

        }
        return tail->next;
    }
};
