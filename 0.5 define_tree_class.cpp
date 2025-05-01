
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};


int main()
{
    TreeNode* a = new TreeNode();
    cout<<a->val<<endl;   //output = 0
    
    TreeNode* b = new TreeNode(7);
    cout<<b->val<<endl;   //output = 7
    
    TreeNode* c = new TreeNode(5, a, b);
    cout<<c->val<<" "<<(c->left)->val<<" "<<(c->right)->val<<endl;   //output = 5, 0, 7

    return 0;
}
