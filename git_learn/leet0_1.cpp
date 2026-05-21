#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left = nullptr;
        right = nullptr;
    }
};

bool isNullNode(const string& s){
    return s== "None"|| s=="none" || s=="NULL" || s=="null";
}

vector<string> parseInput(string line){
    vector<string> tokens;
    for(char& c:line){
        if(c=='['|| c==']' || c==','){
            c = ' ';
        }
    }
    stringstream ss(line);
    string token;
    while(ss>>token){
        tokens.push_back(token);
    }
    return tokens;
}

TreeNode* buildTree(const vector<string>& tokens){
    if(tokens.empty()){
        return nullptr;
    }
    if(isNullNode(tokens[0])){
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    int n=tokens.size();

    while(!q.empty() && index<n){
        TreeNode* cur = q.front();
        q.pop();

        if(index<n && !isNullNode(tokens[index])){
            cur->left = new TreeNode(stoi(tokens[index])); 
            q.push(cur->left);
        }
        index++;
        if(index<n && !isNullNode(tokens[index])){
            cur->right = new TreeNode(stoi(tokens[index])); 
            q.push(cur->right);
        }
        index++;
    }
    return root;
}
void dfsFromNode(TreeNode* node, int cursum, int pathlen, int& ans){
    if(node == nullptr){
        return;
    }
    cursum += node->val; pathlen++;
    if(pathlen>=2 && cursum==0){
        ans++;
    }
    dfsFromNode(node->left, cursum, pathlen, ans);
    dfsFromNode(node->right, cursum, pathlen, ans);
}

void traverse(TreeNode* root, int& ans){
    if(root == nullptr){
        return;
    }
    dfsFromNode(root, 0, 0, ans);
    traverse(root->left, ans);
    traverse(root->right, ans);
}

int main(){
    string line;
    getline(cin,line);
    vector<string> tokens = parseInput(line);
    TreeNode* root = buildTree(tokens);
    int ans=0;
    traverse(root, ans);
    cout<<ans<<endl;
    return 0;
}
