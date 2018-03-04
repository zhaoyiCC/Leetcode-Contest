# Leetcode-Contest-74
    
[题目传送门](https://leetcode.com/contest/weekly-contest-74/)

一次不错的练习，四道题难度相似。


## A. Valid Tic-Tac-Toe State


题目的大意就是两个人轮流下棋，棋盘是3*3，然后行列对角线填满一种就结束，问能否到达某种状态。

做的时候头脑一根筋了，偏偏要暴力dfs下所有的状态。然后第一次没有状态判重还TLE了下。

其实直接判断几种不符合条件的情况即可。

## B. Number of Matching Subsequences

题目的大意就是给你一个字符串S，判断另一个字符数组有多少是S的子序列（不是子串，即可以不连续）

直接暴力TLE，我们把每个字母出现的位置放到一个vector里，显然是递增的。然后对于每个子串，直接二分出下一个字母从哪个S的位置开始。找不到就不是，否则可以一步步找到。

## C. Number of Subarrays with Bounded Maximum

题目难得大意就是给定一个序列，求最大的数在[L,R]的子区间的个数。

我用扫描法做的。当然这个方法更清晰：

```
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result=0, left=-1, right=-1;
        for (int i=0; i<A.size(); i++) {
            if (A[i]>R) left=i;
            if (A[i]>=L) right=i;
            result+=right-left;
        }
        return result;
    }
};
```

## D. Preimage Size of Factorial Zeroes Function

题目的大意就是求n!末尾个数是K的n有多少个。

首先，对于一个数n的阶乘的末尾0的个数，这个直接求n的分解质因数的5的个数，所以不停的/5统计就行。

```
int countZero(int x){
   int res = 0;
   while (x != 0){
       res += x/5;
       x/=5;
   }
   return res;
}
```

然后对于题目的要求，我们可以发现，随着n的增大，显然0的个数在增多。因此满足递增的性质，我们只要统计n!的末尾0的个数<=K再减去统计n!的末尾0的个数<=K-1即可。




