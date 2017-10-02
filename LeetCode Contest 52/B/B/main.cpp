//
//  main.cpp
//  B
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, a[N];


// Definition for a binary tree node.
 struct TreeNode {
    int val;
  TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
    这个题的关键在于抓住这样的特点，所有的树根的值都是由左子树可以求出的值加上右子树加上的值，然后子树的值是由左子树和子树的较大值来决定的。具体可参见下图。树根的26是可以由左子树和右子树的值相加，但是子树却不行，因为子树再选取和的话就无法构成书树上的路径了。
    理解了这一点，就不会把下图的答案算成5了。这个图的答案应该是4.
 */


//思路1： 和之前的那个值做比较，如果不相等就代表不是一个序列下来的，否则就是同一颜色。
class Solution2 {
public:
    int ans = 0;
    int dfs(TreeNode* root, int preVal){
        int l=0, r=0;
        if (root->left != NULL)
            l = dfs(root->left, root->val);
        if (root->right != NULL)
            r = dfs(root->right, root->val);
        ans = max(ans, l+ r);
        if (root->val == preVal)
            return max(l,r)+1;
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root)
            dfs(root, 1e9);
        return ans;
    }
};

//思路2：每次都以每个点为根做一次，那么此时就很简单，判断子树有多少是和根的值是一样的就好了。
class Solution {
public:
    int ans = 0;
    int work(TreeNode* root){
        int l = 0, r = 0;
        if (root->left != NULL && root->left->val == root->val)
            l = work(root->left);
        if (root->right != NULL && root->right->val == root->val)
            r = work(root->right);
        return max(l, r)+1;
    }
    void dfs(TreeNode* root){
        if (root==NULL)
            return ;
        int l = 0, r = 0;

        
        if (root->left&& root->left->val == root->val){
            l = work(root->left);
            ans = max(l, ans);
        }
        if (root->right&& root->right->val == root->val){
            r = work(root->right);
            ans = max(r, ans);
        }
        ans = max(l+r, ans);
        dfs(root->left);
        dfs(root->right);
        return ;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};

int main() {

    typedef TreeNode tn;
    tn t(5);
    tn t1(4);
    tn t11(1);
    tn t12(1);
    tn t2(5);
    tn t22(5);

//    tn t(1);
//    tn t1(4);
//    tn t11(4);
//    tn t12(4);
//    tn t2(5);
//    tn t22(5);
    
    t1.left = &t11;
    t1.right = &t12;
    t.left = &t1;
    
    t2.right = &t22;
    t.right = &t2;
    
    Solution s;
    ans = s.longestUnivaluePath(&t);
    
    
    
    cout << ans << endl;

    return 0;
}
