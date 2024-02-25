/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q;
        for(auto head : lists) {
            if(head) q.push(head);
        }
        auto dummyNode = new ListNode(-1);
        auto p = dummyNode;
        while(!q.empty()) {
            auto node = q.top();
            q.pop();
            p->next = node;
            p = p->next;
            if(node->next) q.push(node->next);
        }
        return dummyNode->next;
    }
};
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