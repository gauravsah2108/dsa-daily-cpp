#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

TreeNode* buildTree(const vector<string>& nodes){
    if(nodes.empty()|| nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*>q;

    q.push(root);

    int i=1;

    while(!q.empty() && i<nodes.size()){
        TreeNode* current =q.front();
        q.pop();

        if(i<nodes.size() && nodes[i] != "null"){
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if(i<nodes.size() && nodes[i]!="null"){
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int> level;

        for(int i =0;i<size;++i){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        result.push_back(level);

    }

    return result;
}

void print(const vector<vector<int>>& levels){
    for(const auto& level:levels){
        for(int val:level) cout<<val<<" ";
        cout<<"\n";
    }
}

int main(){

    cout << "Enter tree nodes in level order (use 'null' for missing):\n";
    // Example input: 3 9 20 null null 15 7

    string line;
    getline(cin, line);

    // Split input into tokens
    // Replace commas with spaces
    for (char &c : line) {
        if (c == ',') c = ' ';
    }

    stringstream ss(line);
    vector<string> nodes;
    string token;
    while (ss >> token) {
        nodes.push_back(token);
    }


    TreeNode* root = buildTree(nodes);
    vector<vector<int>> levels = levelOrder(root);

    cout << "\nLevel order traversal:\n";
    print(levels);
    return 0;
}