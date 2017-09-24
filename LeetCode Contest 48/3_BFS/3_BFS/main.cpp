//
//  main.cpp
//  3_BFS
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

using namespace std;


int ans, n , m, a[10010];
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        // get all the tree positions and sort based on height
        // trees[i][0] is height. The default comparison of vector compare first element before other elements.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 0) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        // accumulate all the paths
        for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++) {
            int step = next_step(i, forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            // if next tree cannot be reached, step = -1;
            if (step == -1) return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
            cout << i <<"!!!"<<step<<endl;
        }
        return ans;
    }
private:
    // BFS to find shortest path to next tree; if cannot reach next tree, return -1
    int next_step(int id,vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> myq;
        myq.push({sr, sc});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                if (id == 20){
                    exit(0);
                }
                    cout << row<<" "<<col<<endl;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
};
class Solution3 {
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
public:
    int n,m,ans;
    
    const static int N = 55;
    const static int maxn = 2510;
//    bool b[N][N];
    
    int xx[5]={-1,0,1,0};
    int yy[5]={0,1,0,-1};
   
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> v;
        int x[maxn], y[maxn];
        n = forest.size();
        m = forest[0].size();
        rep (i,0,n-1)
        rep (j,0,m-1){
            if (forest[i][j] > 0)
                v.push_back({forest[i][j],i,j});
        }
        sort(v.begin(), v.end());
        int siz = (int) v.size();
        x[0] = 0;
        y[0] = 0;
        rep (i,0,siz-1){
            x[i+1] = v[i][1];
            y[i+1] =v[i][2];
        }
        
        int fromx, fromy, tox, toy;
        ans = 0;
        
        rep (i, 0, siz-1){
            
            fromx = x[i];
            fromy = y[i];
            
            tox = x[i+1];
            toy = y[i+1];
            if (fromx == tox && fromy == toy){
                continue;
            }
            int step = bfs(i, forest,fromx, fromy, tox, toy);
            if (step == -1)
                return -1;
            ans += step;
            cout<<i<<"！！！"<<step<<endl;
        }
        
        
        
        return ans;
    }
private:
    bool isValid(int x,int y,vector<vector<int>>& forest){
        return (x>=0&&x<n&&y>=0&&y<m&&forest[x][y]>0);
    }
    int bfs4(int id,vector<vector<int>>& forest, int sr, int sc, int er, int ec){
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
         cout << m << " ###"<< n << endl;
        queue<pair<int, int>> myq;
        myq.push({sr, sc});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                if (id == 20){
                    exit(0);
                }
                cout << row<<" "<<col<<endl;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
    int bfs(int id,vector<vector<int>>& forest,int fromx, int fromy, int tox, int toy){
        //        bool b[N][N];
        //        memset(b, false, sizeof(b));
        cout << n << " "<<m << endl;
        vector<vector<int>> b(n, vector<int>(m, 0));
        b[fromx][fromy] = true;
        
        queue<pair<int,int>> q;
        
        q.push(make_pair(fromx, fromy));
        int nowx, nowy, newx, newy;
        int steps = 0;
        while (!q.empty()){
            steps++;
            int s = q.size();
            rep (j,0,s-1){
                nowx = q.front().first;
                nowy = q.front().second;
                if (id==20)
                    exit(0);
                cout << nowx<< " " << nowy<< endl;
                q.pop();
                rep (k,0,3){
                    newx = nowx+xx[k];
                    newy = nowy+yy[k];
                    if (newx == tox && newy == toy)
                        return steps;
                    
                    //                    if (newx>=0&&newx<n&&newy>=0&&newy<m&&forest[newx][newy]>0&&!b[newx][newy]){
                    if (isValid(newx, newy, forest)&&!b[newx][newy]){
                        q.push(make_pair(newx, newy));
                        b[newx][newy] =  true;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    freopen("/Users/Mr.ZY/Documents/Program/LeetCode Contest 48/3_BFS/1.txt","r",stdin);
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
    
    
    
    
    
    Solution3 s;
    ans = s.cutOffTree(v);
    cout << ans << endl;
}
