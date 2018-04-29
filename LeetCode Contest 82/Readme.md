# Leetcode-Contest-82
    
[题目传送门](https://leetcode.com/contest/weekly-contest-82/)

一次比较简单的联系，再次手速慢措施ak。第三次第四题一开始都写错了然后才意识过来。

## C. Most Profit Assigning Work

题目的大意就是给定序列difficulty，profit，worker，然后对于每一个worker，求小于等于它的diffculty对应的profit的最大值，最后求和。

我用扫描法做的。当然这个方法更清晰：

被我写成了二分+树状数组，即考虑difficulty小于等于它的最大的那个下标，然后对于下标维护了profit的树状数组。

当然，这个题目明显有更简单的解法。我们可以直接维护一个序列，代表到该点的profit的最大值，我们先用difficty[i]的profit来存进来，再扫一遍和i-1取一个大的就行了。

或者也可以考虑扫描法，就是将difficulty排序，profit也排序，每一个profit从小到大来找，不停的往difficulty后面扫描，用value表示当前最大的profit就好了。

## D. Making A Large Island

水题，直接暴力每个为0的点更新成1就行了。时间复杂度是O(50\^4)，其中dfs的时间复杂度是50\^2，因为状态数就是这么多。

