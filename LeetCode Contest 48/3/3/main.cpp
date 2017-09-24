//
//  main.cpp
//  3
//
//  Created by ohazyi on 2017/9/10.
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
class Solution {
public:
    struct node{
        int x,y,i;
    }zy[10010];

    static bool cmp(node a, node b){
        return (a.i < b.i);
    }
    queue<int> qx;
    queue<int> qy;
    queue<int> qt;
    int a[10001], b[10001];
    int N_M,tot,n,m,x,y,t,h;
    struct Edge{
        int to,cost,next;
    };
    Edge e[50010];
    int e_sum,head[50010];
    void addedge(int x,int y,int z)
    {
        e[e_sum].next = head[x];
        e[e_sum].to = y;
        e[e_sum].cost = z;
        head[x] = e_sum++;
    }
    void spfa(int start,int (&dist)[10001])
    {
        int u,i,j,v,h;
        bool vis[10010];
        memset(vis,false,sizeof(vis));
        
        queue <int>q;
        dist[start] = 0;
        q.push(start);
        vis[start] = true;
        while (!q.empty())
        {
            v=q.front();
            q.pop();
            for (i = head[v]; i != -1; i=e[i].next)
            {
                u = e[i].to;
                h = e[i].cost;
                if (dist[v]+h<dist[u])
                {
                    dist[u] = dist[v]+h;
                    if (vis[u]==false)
                    {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
            vis[v] = false;
        }
    }
    
    int work(int x,int y,vector<vector<int>>& forest){
        if (x < 0 || x >= n)
            return -1;
        if (y < 0 || y >= m)
            return -1;
        if (forest[x][y] == 0)
            return -1;
        return N_M*x+y;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        memset(head,-1,sizeof(head));

        n = (int)forest.size();
        m = (int)forest[0].size();
        N_M = (n > m) ? n : m;
        
        qx.push(0);
        qx.push(0);
        qt.push(0);
        tot = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (forest[i][j] != 0){
                    h = forest[i][j];
                    zy[++tot].x = i;
                    zy[tot].y = j;
                    zy[tot].i = h;
                }
            }
        }
        sort(zy+1, zy+tot+1, cmp);
        for (int i = 1; i <= tot; ++i){
            a[i] = zy[i].x;
            b[i] = zy[i].y;
        }
        
        int hh[5];
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (forest[i][j] == 0)
                    continue;
                h = N_M*i+j;
                hh[1] = work(i-1,j, forest);
                hh[2] = work(i+1,j, forest);
                hh[3] = work(i,j-1, forest);
                hh[4] = work(i,j+1, forest);
                for (int k = 1;  k <= 4; ++k){
                    if (hh[k]!=-1&&h!=hh[k]){
                        addedge(h, hh[k], 1);
                    }
                }
            }
        }
        
        int lx,ly, nx, ny;
        lx = ly = 0;
        int dis[10001];
        int ans = 0;
        int des;
        for (int i = 1; i <= tot; ++i){
            nx = a[i];
            ny = b[i];
            h = N_M*nx+ny;
            memset(dis,0x3f,sizeof(dis));
            spfa(h, dis);
            des = N_M*lx+ly;
            if (dis[des]>n*m){
                return -1;
            }
            ans+=dis[des];
            lx = nx;
            ly = ny;
        }
        return ans;
    }
};

int main() {

    int x;
    cin >> n >> m;
    vector<int> vvv;
    vector<vector<int>> v;
    rep (i, 1, n){
        vvv.clear();
        rep (j,1,m){
            scanf("%d",&x);
            vvv.push_back(x);
        }
        v.push_back(vvv);
    }
    

    
    
    
    Solution s;
    ans = s.cutOffTree(v);
    cout << ans << endl;
}
