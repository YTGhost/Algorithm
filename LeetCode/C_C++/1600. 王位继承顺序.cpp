class Node {
public:
    string name;
    vector<Node*> children;

    Node(string name) : name(name) {}
};

class ThroneInheritance {
public:
    Node *root;
    unordered_map<string, Node*> name2Node;
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        name2Node[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        auto parent = name2Node[parentName];
        auto child = new Node(childName);
        name2Node[childName] = child;
        parent->children.push_back(child);
    }
    
    void death(string name) {
        name2Node.erase(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        function<void(Node*)> dfs = [&](Node *root) {
            if(!root) return;
            if(name2Node.find(root->name) != name2Node.end()) {
                res.push_back(root->name);
            }
            for(auto child : root->children) {
                dfs(child);
            }
        };
        dfs(root);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */