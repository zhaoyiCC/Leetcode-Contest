# Leetcode-Contest-55    [题目传送门](https://leetcode.com/contest/weekly-contest-55/)在Linux下的Codeblocks写的，不过忘了单个文件是只能执行不能debug了，因此一直输出来调试有点浪费时间。最后只做出B和C，A最后时间不够了，写完之后发现还有一个输入的变量没有考虑进去。不过最后竟然rating不到300，有点意外了。## A. Repeated String Match题意是，给你一段序列，我们可以认为这是股票的价值。然后你可以在某个时刻买一个股票，在之后的某一时刻卖掉。在买下一个股票之前必须先卖掉手里的，然后每次卖出需要花费fee的价值。求最大的价值。

一开始我做的时候忽视了fee的影响，以为直接找到这段序列的极值点就行了，然后发现样例都过不了。因为1->3、2->8这样的价值是0+4=4，而直接1->8的价值是5。

正确做法是DP.每个状态的买和卖的情况之和前一个状态有关，比较巧妙的是用-prices[i]来代表买。

```
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int f[60010][2], i;
        f[0][0] = -1e9;
        f[0][1] = 0;
        rep (i,1,(int)prices.size()) {
            f[i][0] = max(f[i-1][0], f[i-1][1] - prices[i-1]);  // buy
            f[i][1] = max(f[i-1][1], f[i-1][0] + prices[i-1] - fee); // sell
        }
        return f[prices.size()][1];
    }
};

```
## B. Minimum ASCII Delete Sum for Two Strings水DP. ## C. Subarray Product Less Than K求一段序列里面的连续子序列的个数，这些子序列的乘机要小于k. n <= 1e5.

类似尺取法的思想，每次都尽可能扫到尾，然后到下一个元素就把首元素给收缩掉（如果当前存在序列使得满足条件），我一开始写的时候饶了自己一下，被一个边界条件卡了一下，多交了一发。

然后不知道为什么这个题很多人用的是O(n\^2)，而且我challenge他们代码的时候也是卡在那儿不动(就是明明TLE了也不动)，有点玄学。不然感觉我这一次的排名还能上升一点owo。
## D有空再补

