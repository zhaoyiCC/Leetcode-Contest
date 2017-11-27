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

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, a[N];
class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    bool b[101][101];
    int nx, ny, tx, ty;
    
    int xx[5] = {0,1,0,-1};
    int yy[5] = {-1,0,1,0};
    queue<int> qx;
    queue<int> qy;

    int n, m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> vans;
        vans = image;
        
        memset(b,false,sizeof(b));
        if (image.size()==0)
            return image;
        
        n = image.size();
        m = image[0].size();
        
        vans[sr][sc] = newColor;
        qx.push(sr);
        qy.push(sc);
        b[sr][sc] = true;
        while (!qx.empty()){
            nx = qx.front();
            ny = qy.front();
            qx.pop();
            qy.pop();
            rep (k,0,3){
                tx = nx + xx[k];
                ty = ny + yy[k];
                if (tx >= 0 && ty >= 0 && tx< n && ty<m && image[tx][ty] == image[sr][sc] && !b[tx][ty]){
                    qx.push(tx);
                    qy.push(ty);
                    vans[tx][ty] = newColor;
                    b[tx][ty] = true;
                }
            }
        }
        return vans;
    }
    
};



int main() {
    
    int x;
    vector<vector<int>> v;
    cin >> n >> m;
    rep (i,1,n){
        vector<int> v2;
        rep (j,1,m){
            cin >> x;
            v2.push_back(x);
        }
        v.push_back(v2);
    }
    ans = 0;
    Solution s;
    vector<vector<int>> va;
    va = s.floodFill(v, 1, 1, 2);
    rep (i,0,n-1){
        rep (j,0,m-1){
            cout << va[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
