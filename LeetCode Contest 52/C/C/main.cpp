//
//  main.cpp
//  C
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
    int n;
    int xx[9]={1,2,2,1,-1,-2,-2,-1};
    int yy[9]={2,1,-1,-2,-2,-1,1,2};
    double f[30][30][110];
    bool find(int x,int y){
        return (x >=0  && y>=0 && x<=n-1 && y<=n-1);
    }
    double knightProbability(int N, int K, int r, int c) {
        n = N;
        int tot=0;
        memset(f,0,sizeof(f));
        f[r][c][0] = 1;
        rep (p,0,K)
        rep (i,0,N-1)
        rep (j,0,N-1)
        if (f[i][j][p]>0)
        {
            tot = 0;
            rep (k,0,7){
                if (find(i+xx[k], j+ yy[k])){
                    f[i+xx[k]][j+yy[k]][p+1]+=1.0*f[i][j][p]/8;
                }
//                    tot++;
            }
//            f[i][j] = 1.0*tot/8;
        }
        double res = 0;
        rep (i,0,N-1)
        rep (j,0,N-1)
        if (f[i][j][K]>0){
            res += f[i][j][K];
//            cout << i << j  <<f[i][j][K];
        }
        return res;
    }
};

int main() {

    int n,k,r,c;

    ans = 0;
    Solution s;
    cin >> n >> k >> r >> c;
    double zy = s.knightProbability(n, k, r, c);
    cout << zy << endl;

    return 0;
}
