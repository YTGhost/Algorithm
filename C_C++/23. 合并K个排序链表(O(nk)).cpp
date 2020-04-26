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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        while(true)
        {
            ListNode* minNode = NULL;
            int sign = -1;
            for(int i = 0; i < k; i++)
            {
                if(!lists[i]) continue;
                if(!minNode || lists[i]->val < minNode->val)
                {
                    sign = i;
                    minNode = lists[i];
                }
            }
            if(sign == -1) break;
            tail->next = minNode;
            tail = tail->next;
            lists[sign] = lists[sign]->next;
        }
        return dummyHead->next;
    }
};