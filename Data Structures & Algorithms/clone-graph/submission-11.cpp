class Solution {

public:
    unordered_map<Node*,Node*>visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if(visited[node]!=nullptr) {return visited[node];}

        Node* root=new Node(node->val);
        visited[node]=root;
        
        for(auto child:node->neighbors){
            root->neighbors.push_back(cloneGraph(child));
        }
        return root;
    }
};