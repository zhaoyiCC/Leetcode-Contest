# Leetcode-Contest-70
    
[题目传送门](https://leetcode.com/contest/weekly-contest-70/)

又是300名出头，尴尬的名次。手速还是不够啊，结束后没多久把第二题那个树的递归处理过了，对这种处理指针的递归题还是不是很熟悉。 

## A. K-th Symbol in Grammar

一个序列，初始是1.然后每次迭代，不停地用01替换1，10替换1.问第N次迭代后的第k位是什么。

这种从后一个结果往前推的题通常都是递归。找一下前后的规律，写递归即可。

## B. Split BST

给定一个的BST和整数V，然后拆分成两个BST. 一个BST的全部节点是大于V的，另一个则是小于等于V。

仍然是一道递归题。我当时的做法的思路是这样的：先考虑如何求比V大的子树。对于每一个子树，先递归求好左子树和右子树。如果其根节点比V小，那么返回它的右子树(因为左子树的结果都比V还要小，更不可能加入到结果的子树里)；如果根节点比V大，那么就返回这棵树就好了。同样的思路求比V小于等于的树。

这个思路没有什么问题，但我在写的时候忽略了这样的一点：由于是分别计算的，所以我必须得拷贝两份这棵树，否则在第一个结果算完之后，我们再处理第二棵树，就是在第一个已经计算好的结果上进行处理的，这样就GG了。

```
//        TreeNode *Ltemp = root;      
//        TreeNode *Rtemp = root;
        TreeNode* Ltemp = copyTree(root);
        TreeNode* Rtemp = copyTree(root);
        v1 = addBST1(Ltemp, V);
        v2 = addBST2(Rtemp, V);
```

一开始注释掉的那两行是想直接用Ltemp来拷贝一个新的，但它们的子树信息还是用的同样的地址。因此必须完全地进行拷贝一遍：

```
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
```

过是过了，但感觉这个递归写的很不优雅，尤其是分下来计算两棵树，没有充分利用到它们并起来就是原来树的这样的特点。看了讨论区，发现原来大家都是这么写的：

```
vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode *> res(2, NULL);
        if(root == NULL) return res;
        
        if(root->val > V){
            res[1] = root;
            auto res1 = splitBST(root->left, V);
            root->left = res1[1];
            res[0]=res1[0];
        }else{
            res[0] = root;
            auto res1 = splitBST(root->right, V);
            root->right = res1[0];
            res[1] = res1[1];
        }
        
        return res;
    }
```

解释一下：
首先res[0]代表的是值<=V的子树，res[1]代表的是值>V的子树。
每一个节点都肯定在子树1或者子树2。然后对于当前树的根节点>V的树，显然root节点和全部右子树是包括进去res[1]的，然后左边的树也有可能有部分在res[1]里。此时我们递归求左子树，把结果放在假定叫RES的vector里，然后RES[0]的结果显然就是我们的res[0]，同时把root的左子树更新为RES[1]。类似的思想，处理对于当前树的根节点<=V的树。

我觉得核心思想是怎么充分利用给定的函数，而不是需要我们另起炉灶。相当于在一棵树上处理好所有的操作。


## C. Swap Adjacent in LR String

题意大概就是：
一个字符串，包括R L X三个字母，例如"RXXLRXRXL"。可以把XL换成LX，把RX换成XR。读入字符串A和B, 问能否从字符串A通过变化变化到B。判断true或false.

例如样例：

> Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

拿到题的第一想法是直接遇到一个原串是XL匹配串是LX的就匹配，同理对于第二个。然后果断WA。因为存在这样的情况，
start="XXXXXXXXXL" end="LXXXXXXXXX"。我们就可以通过不停地把XL换成LX一直往左匹配到最左边。

然后我们就可以发现，对于XL->LX和RX->XR是不冲突的，即可以先处理是否L都可以互相匹配再匹配R（因为XL->LX的这个X是不会再采用RX->XR这样的规则的）

所以遇到初始串是X匹配串是L的，我们就在初始串中往后抓一个最近的L来和该位置的X进行交换(该过程不能遇到R，因为这个L是一步步向左移到这个X的)。对于RX->XR，其思想类似。

（ps：我发现contest的测试例子和之后的例子不完全一样，即我拿比赛时AC的代码再测了发现漏了start=RL, end=LR这样的情况，少了一个判断，看来LeetCode的contest还是很人性化的，这要是CF又得伤心的FST）


评论区的这位老铁的java思路也很清晰：

```
class Solution {
    public boolean canTransform(String start, String end) {
        if (!start.replace("X", "").equals(end.replace("X", "")))
            return false;
        
        int p1 = 0;
        int p2 = 0;
        
        while(p1 < start.length() && p2 < end.length()){
            
            // get the non-X positions of 2 strings
            while(p1 < start.length() && start.charAt(p1) == 'X'){
                p1++;
            }
            while(p2 < end.length() && end.charAt(p2) == 'X'){
                p2++;
            }
            
            //if both of the pointers reach the end the strings are transformable
            if(p1 == start.length() && p2 == end.length()){
                return true;
            }
            // if only one of the pointer reach the end they are not transformable
            if(p1 == start.length() || p2 == end.length()){
                return false;
            }
            
            if(start.charAt(p1) != end.charAt(p2)){
                return false;
            }
            // if the character is 'L', it can only be moved to the left. p1 should be greater or equal to p2.
            if(start.charAt(p1) == 'L' && p2 > p1){
                return false;
            }
            // if the character is 'R', it can only be moved to the right. p2 should be greater or equal to p1.
            if(start.charAt(p1) == 'R' && p1 > p2){
                return false;
            }
            p1++;
            p2++;
        }
        return true;
    }
}
```

## D. Swim in Rising Water

有空再补！


