struct comp{
    
    bool operator()(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;// MIN HEAP, DEFAULT IS MAX HEAP
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = NULL;ListNode* tail = NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;
        
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        
        while(!pq.empty()){
            
            ListNode* ln = pq.top();
            if(head==NULL){
                head = ln, tail=ln;
            }
            else{
                tail->next=ln;
                tail=ln;
            }
            pq.pop();
            ln=ln->next;
            if(ln!=NULL)
                pq.push(ln);
        }
        return head;
    }
};
