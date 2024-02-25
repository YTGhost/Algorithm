/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(map.find(node) != map.end()) {
            return map[node];
        }
        auto copy = new Node(node->val);
        map[node] = copy; 
        for(auto& neighbor : node->neighbors)
        {
            copy->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return copy;
    }
};