#include <iostream> //94 二叉树中序遍历
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
bool isNullNode(const string& s){
    return s=="None" || s=="none";
}
vector<string> Inputline(string line){
    vector<string> nodeTexts;
    for(char& ch : line){
        if(ch==','){
            ch = ' ';
        }
    }
    stringstream ss(line);
    string a;
    while(ss>>a){
        nodeTexts.push_back(a);
    }
    return nodeTexts;
}

TreeNode* buildTree(const vector<string>& nodeTexts){
    if(nodeTexts.empty()){
        return nullptr;
    }
    if(isNullNode(nodeTexts[0])){
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(nodeTexts[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1, n= nodeTexts.size();

    while (!q.empty() && index < n)
    {
        TreeNode* cur = q.front();
        q.pop();
        if(index<n && !isNullNode(nodeTexts[index])){
            cur->left = new TreeNode(stoi(nodeTexts[index]));
            q.push(cur->left);
        }
        index++;
        if(index<n && !isNullNode(nodeTexts[index])){
            cur->right = new TreeNode(stoi(nodeTexts[index]));
            q.push(cur->right);
        }
        index++;
    }
    return root;
}
void inorderTraversal(TreeNode* root, vector<int>& res){
    if(root==nullptr){
        return;
    }
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}
int main(){
    string line;
    getline(cin,line);
    vector<string> nodeTexts = Inputline(line);
    TreeNode* root = buildTree(nodeTexts);
    vector<int> res;
    inorderTraversal(root, res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<', ';
    }
    return 0;
}

