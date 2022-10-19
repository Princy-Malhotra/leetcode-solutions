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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
        {
            TreeNode* temp = new TreeNode(head->val);
            return temp;
        }
        
        ListNode* temp = head;
        int n=0;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        
        int mid = (n%2!=0)?(n/2+1):n/2;
        //TreeNode* t = new TreeNode(mid);
        //return t;
        ListNode* temp1 = head;
        int i=2;
        ListNode* temp2 = head->next;
        
        if(n==2)
        {
            TreeNode* root = new TreeNode(temp2->val);
            TreeNode* rootleft = new TreeNode(temp1->val);
            root->left = rootleft;
            return root;
        }
        
        while(i!=mid && temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            i++;
        }
        /*if(temp2==NULL)
        {
            temp1->next = NULL;
            return sortedListToBST(head);
        }*/
        
        TreeNode* root = new TreeNode(temp2->val);
        temp1->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(temp2->next);
        return root;
    }
};