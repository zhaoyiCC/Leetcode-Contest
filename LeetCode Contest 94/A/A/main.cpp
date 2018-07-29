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
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> v[2];
    void mywork(TreeNode* root, int type){
        bool zy = true;
        if (root->left){
            mywork(root->left, type);
            zy = false;
        }
        if (root->right){
            mywork(root->right, type);
            zy = false;
        }
        if (zy)
            v[type].push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        mywork(root1, 0);
        mywork(root2, 1);
        if (v[0].size() != v[1].size())
            return false;
//        sort(v[0].begin(), v[0].end());
//        sort(v[1].begin(), v[1].end());
        rep (i,0,(int)v[0].size()-1){
            if (v[0][i] != v[1][i])
            return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    
    string zy = s.toGoatLatin("The quick brown fox jumped over the lazy dog");
    cout << zy << endl;
    return 0;
}
