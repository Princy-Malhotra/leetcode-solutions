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
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            Node* temp = NULL;
            return temp;
        }
        
        /*if(node->neighbors.size()==0)
        {
            Node* temp = new Node(node->val);
            return temp;
        }
        
        Node* temp = new Node(node->val);
        int n = node->neighbors.size();
        temp->neighbors.resize(n);
        for(int i=0;i<n;i++)
        {
            temp->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return temp;*/
        unordered_map<Node*,Node*>mp;
        Node* temp = node;
        Node* nroot = new Node(temp->val);
        Node* nhead = nroot;
        mp[temp]=nroot;
        
        queue<Node*>q;
        q.push(temp);
        
        while(!q.empty())
        {
            Node* t = q.front();
            q.pop();
            if(t!=NULL)
            {
                for(int i=0;i<t->neighbors.size();i++)
                {
                    if(mp[t->neighbors[i]]==NULL)
                    {
                        nroot = new Node(t->neighbors[i]->val);
                        mp[t->neighbors[i]]=nroot;
                        q.push(t->neighbors[i]);
                    }
                    mp[t]->neighbors.push_back(mp[t->neighbors[i]]);
                }
            }
            else
            mp[t]=NULL;
        }
        
        return nhead;
    }
};