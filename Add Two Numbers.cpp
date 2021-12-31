class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* lastNode=NULL, *root = NULL;
        
        int sum = 0, carry = 0;
        
        while(l1!=NULL && l2!=NULL){
            int x=l1->val;
            int y=l2->val;
            
            sum = carry+x+y;
            
            int value = sum%10;
            carry = sum/10;
            
            ListNode* node = new ListNode(value);
            if(root==NULL)
                root=node;
            else
                lastNode->next = node;
            
            lastNode = node;
            
            l1=l1->next;l2=l2->next;
        }
        
        while(l1!=NULL){
            int x=l1->val;
            
            sum = carry+x;
            
            int value = sum%10;
            carry = sum/10;
            
            ListNode* node = new ListNode(value);
          if(root==NULL)
                root=node;
            else
                lastNode->next = node;
            
            lastNode = node;
            
            l1=l1->next;
        }
        
        while(l2!=NULL){
             int y=l2->val;
            
            sum = carry+y;
            
            int value = sum%10;
            carry = sum/10;
            
            ListNode* node = new ListNode(value);
          if(root==NULL)
                root=node;
            else
                lastNode->next = node;
            
            lastNode = node;
            
            l2=l2->next;
        }
        
        if(carry!=0){
           ListNode* node = new ListNode(carry); 
            lastNode->next = node;
        }
        
        return root;
    }
};
