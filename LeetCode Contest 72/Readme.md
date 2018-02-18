# Leetcode-Contest-72
    
[题目传送门](https://leetcode.com/contest/weekly-contest-72/)

第一次杀入前200名(刚刚卡进去)，第三题写的时候浪费了很长时间在一开始的BFS上，意识到是dp之后才意识到多简单，第四题没时间写了不过估计有时间也在比赛的时候写不出。第一次发现在LeetCode上直接运行的便利。


## C. Cheapest Flights Within K Stops


求从源点到目标点在指定步数之内的最短距离。100个点。10000条边。

一开始的BFS的替换条件写搓了，导致然后写了一个DP版本的去交ac了。刚刚发现BFS并不会超时，注意到后更新的点它的停靠站肯定会更多，所以我们只要距离变短的加入到队列里就好了。BFS当用的是邻接表的时候的时间复杂度是O(|V|+|E|)，当然不会超时。不过dp也很好写了。（另外，这种分步数的BFS可以如下面这样写，这样就不用存步数信息到队列里了）

```
while(!index.isEmpty()){
        int sz = index.size();
        for(int i=0;i<sz;i++){
            ....
        }
        step++;
```



## D. K-th Smallest Prime Fraction

题目的大意就是：给你一个序列(每个数都是素数)，然后对于序列里的x<y的，可以构成分数。问第k小的分数是多少。其中序列长度2000，序列里的值<=30000。

一开始以为是二分题，后来想了想也没什么思路。看了别人提交的代码，整理出三个思路，分别说下。主要的思想还是发现每个序列的一些次序关系，并尽心抽丝剥茧。

1、 考虑相同的分子的分数，它们每一组是有序的，例如序列[1, 7, 23, 29, 47]

> 
1/47  < 1/29    < 1/23 < 1/7
7/47  < 7/29    < 7/23
23/47 < 23/29
29/47

虽然每一行的最后一个元素和下一行的第一个元素之间没有次序关系，但是这个比较大的数我们并不关心(我们只关心最小的数）。因为我们只要维护一个优先队列，使得这个优先队列里的数，保持能够执行K次，每次的最小值在这个序列里即可。因此最一开始我们把每一刚的行首元素放入队列里，然后不断地弹出队首，并把队首元素的下一个加入到优先队列里。

```
vector<int> aaa;
struct T{
    int x, y;
    bool operator < (T t) const {
        return 1.0*aaa[x]/aaa[y] > 1.0*aaa[t.x]/aaa[t.y];
    }
//    bool operator > (T t) const {
//        return 1.0*aaa[x]/aaa[y] < 1.0*aaa[t.x]/aaa[t.y];
//    }
};
priority_queue<T> v;
class Solution{
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        aaa = A;
        int n = (int)A.size();
        while (!v.empty()) //！！！竟然必须得加上这个初始化，否则LeetCode会WA
            v.pop();
        rep (i,0,n-2){
            v.push(T{i,n-1});
        }
        rep (i,1,K-1){
            T now = v.top();
            int xx = now.x;
            int yy = now.y;
            if (yy!=0){
                v.push(T{xx,yy-1});
            }
            v.pop();
        }
        T now = v.top();
        return {A[now.x], A[now.y]};
    }
};
```

2、 不考虑x/y，而是考虑y/x。这样确定到落在哪个y/x里，然后求一下。参考代码：

```
 bool cmp(pair<int,int> a,pair<int,int> b){  //a.first/a.second<b.first*b.second
        return a.first*b.second<a.second*b.first;
    }

int cnt[30002];

vector<pair<int,int> > vv;

class Solution {
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int idx=0;
        memset(cnt,0,sizeof(cnt));
      for(int i=0;i<A.size();i++){
          for(int j=i+1;j<A.size();j++){
              cnt[A[j]/A[i]]++;
            }
      }  
        int ii=30000;
        while(1){
            if(K<=cnt[ii]){
                break;
            }
            K-=cnt[ii];
            ii--;
        }
        vv.clear();
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                if(A[j]/A[i]==ii){
                    vv.push_back(make_pair(A[i],A[j]));
                }
            }
        }
        sort(vv.begin(),vv.end(),cmp);
        vector<int> ans;
        ans.push_back(vv[K-1].first);
        ans.push_back(vv[K-1].second);
        return ans;
    }
};
```

3、 利用STL的nth_element，在一个无序的数组中找到第K大的元素。

```
double vals[4000010];
class Solution{
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = (int)A.size();
        int tot = 0;
        rep (i,0,n-1){
            rep (j,i+1,n-1){
                vals[tot++] = 1.0*A[i]/A[j];
            }
        }
       
        nth_element(vals, vals+K-1, vals+tot);
        
        rep (i,0,n-1){
            rep (j,i+1,n-1){
                if (1.0*A[i]/A[j] == vals[K-1]){
                    return {A[i], A[j]};
                }
            }
        }
        return {0,0};
    }
};
```


