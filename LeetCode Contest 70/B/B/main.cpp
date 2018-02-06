//
//  main.cpp
//  A
//
//  Created by ohazyi on 2017/10/1.
//  Copyright © 2017年 ohazyi. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

typedef long long ll;

#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];
string str;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    TreeNode* v1;
    TreeNode* v2;

    TreeNode* addBST1(TreeNode* root, int V){
        if (!root)
            return root;
        root-> left = addBST1(root->left, V);
        root-> right = addBST1(root->right, V);
        if (root->val > V){
            return root;
        }else{
            return root->right;
        }
    }
    TreeNode* addBST2(TreeNode* root, int V){
        if (!root)
            return root;
        root-> left = addBST2(root->left, V);
        root-> right = addBST2(root->right, V);
        if (root->val <= V){
            return root;
        }else{
            return root->left;
        }
    }
    
    TreeNode* copyTree(TreeNode* root){
        if (!root)
            return root;
        TreeNode *Ltemp, *Rtemp;
        
        TreeNode* ans = (TreeNode*)(malloc(sizeof(TreeNode)));
        ans->left = ans->right = NULL;//指针初始化，拒绝野指针
        
        ans->val = root->val;
        ans->left = copyTree(root->left);
        ans->right = copyTree(root->right);
        return ans;
    }
    
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root)
            return {v1, v2};
        
//        TreeNode *Ltemp = root;
//        
//        TreeNode *Rtemp = root;
        TreeNode* Ltemp = copyTree(root);
        TreeNode* Rtemp = copyTree(root);
        v1 = addBST1(Ltemp, V);
        v2 = addBST2(Rtemp, V);
        
//        TreeNode *Ltemp = root;
//        TreeNode *Rtemp = root;
//        
//        if (!root->left){
//            
//        }
        
        return {v2, v1};
    }
    
};

int main(){
    typedef TreeNode tn;
    tn t(4);
    tn t1(2);
    tn t11(1);
    tn t12(3);
    tn t2(6);
    tn t21(5);
    tn t22(7);

    
    t1.left = &t11;
    t1.right = &t12;
    t.left = &t1;
    
    t2.left = &t21;
    t2.right = &t22;
    t.right = &t2;
    Solution s;
    s.splitBST(&t, 2);
    
    return 0;
}
