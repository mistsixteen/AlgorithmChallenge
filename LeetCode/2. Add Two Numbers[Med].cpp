class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = 0;
        ListNode* idx = 0;

        ListNode* idxA = l1;
        ListNode* idxB = l2;

        int upwardValue = 0;

        while(idxA != 0 || idxB != 0)
        {
            int temp = upwardValue;

            if(idxA != 0)
            {
                temp = temp + idxA->val;
                idxA = idxA -> next;
            }

            if (idxB != 0)
            {
                temp = temp + idxB->val;
                idxB = idxB -> next;
            }

            upwardValue = temp / 10;

            if(idx == 0)
            {
                idx = new ListNode(temp % 10);
                result = idx;
            }
            else
            {
                idx->next = new ListNode(temp % 10);
                idx = idx->next;
            }
        }

        if (upwardValue != 0)
        {
            idx->next = new ListNode(upwardValue);
            idx = idx->next;
        }

        return result;
    }
};