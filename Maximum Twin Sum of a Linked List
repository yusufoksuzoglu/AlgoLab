class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* theothers = head;
        stack<int> torba;
        int n = 0;
        int twinmax = INT_MIN;
        while (theothers != NULL) {  
            torba.push(theothers->val);
            theothers = theothers->next;
            n++;
        }
        int f = n; 
        while (f >= (n / 2)) { 
            if (head->val + torba.top() > twinmax) {
                twinmax = head->val + torba.top();
            }
            head = head->next;
            torba.pop();
            f--;
        }
        return twinmax;
    }
};
