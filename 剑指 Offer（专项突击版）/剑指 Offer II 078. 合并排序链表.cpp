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
    struct Node {
        int val;
        ListNode* ptr;
        bool operator < (const Node& t) const {
            return val > t.val;
        };
        Node(int x, ListNode* p) : val(x), ptr(p) {}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        auto dummyNode = new ListNode();
        auto ptr = dummyNode;
        for(auto item : lists) {
            if(item) q.push({item->val, item});
        }
        while(!q.empty()) {
            auto item = q.top();
            q.pop();
            if(item.ptr->next) {
                q.push({item.ptr->next->val, item.ptr->next});
            }
            ptr->next = new ListNode(item.val);
            ptr = ptr->next;
        }
        return dummyNode->next;
    }
};