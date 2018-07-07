/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int addtion = 0;
        ListNode * ret = NULL;
        ListNode * p = NULL;
        
        while(l1 || l2)
        {   
            int temp = 0;
            if (l1)
            {
                temp = l1->val;
                l1 = l1->next;
            }  
            if (l2)
            {
                temp += l2->val;
                l2 = l2->next;              
            }
            
            temp += addtion;
            
            if (temp / 10)
            {
                addtion = 1;
                temp %= 10;
            }    
            else
                addtion = 0;
            
            ListNode * t = new ListNode(temp);
            if (p)
            {
                p->next = t;
                p = t;
            }
            else
            {
                ret = t;
                p = t;            
            }
        }
        
        if (addtion)
        {
            ListNode * t = new ListNode(addtion);
            p->next = t;
            p = t;
        }
        
        return ret;
    }
};