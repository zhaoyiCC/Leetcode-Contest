# Leetcode-Contest-51
    
[题目传送门](https://leetcode.com/contest/weekly-contest-51/)

当场做的，过了前三题，手速太慢，第二题还WA了4发(现在才知道错一次是有5min的罚时的) 第四题也比较简单，前三题浪费太多时间导致来不及做了。手速还得提高啊orz

##A. Baseball Game

纯模拟题。

不过学习到了vector的新姿势。比如vector的最后一个元素可以用`v.back()`而不必`v[v.size()-1]`
然后弹出vector的最后一个元素可以直接`v.pop_back()`，而不必`vector<int>::iterator it = a.end();it--;a.erase(it);`

C语言把字符数组转换成整型数的一个函数:
atoi (表示 ascii to integer)
int atoi(const char *nptr);

类似的c++转化string为int的函数是stoi，还有可以转化任意进制的strtol
因此下面三句话等价：


```
a.push_back(stoi(ops[i]));         
a.push_back(strtol(ops[i].c_str(), NULL ,10));                
a.push_back(atoi(ops[i].c_str()));
```

## B. Next Closest Time

暴力。注意时间HH::MM, HH是[0,24], MM是[0,60]。

## C. Redundant Connection

判断一棵多了一条边的树，这条边是哪一条。

我是直接暴力的，判断每条边去掉之后，从一个点开始dfs是否能够走到剩余的所有点。其实用并查集更简单。每次判断每条边的两个点是不是同一个祖先，是的话就输出，否则就放入一个集合里。

## D. K Empty Slots

采取类似**尺取法**的思想。满足题意的要求是找到l和r，使得∀i∈(l,r), bloom[i]>max(bloom[l],bloom[r]).

所以我们就用一个长度为k的线段从左往右扫。对于不满足bloom[i]>max(bloom[l],bloom[r])的，更新l为i，r为l+k+1即可。

AC代码：

```
class Solution {
public:

    int day[20010];
    int ans = 1e9;
    int kEmptySlots(vector<int>& flowers, int k) {
        rep (i,0,(int)flowers.size()-1){
            day[flowers[i]] = i+1;
        }
        int l = 1;
        int r = l+k+1;
        rep (i,2,(int)flowers.size()){
            if (i==l)
                continue;
            if (i == r){
                ans = min(ans, max(day[l], day[r]));
                l = r;
                r = l+k+1;
                continue;
            }
            if (day[i]<=day[l]||day[i]<=day[r]){
                l = i;
                r = l+k+1;
            }
        }
        if (ans==1e9)
            return -1;
        return ans;
    }
};
```


