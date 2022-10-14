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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return NULL;
        
        ListNode* temp = head;
        int n=0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        int mid = n/2;
        
        int y=-1;
        temp = head;
        while(temp)
        {
            y++;
            if(y==mid-1)
            {
                break;
            }
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};