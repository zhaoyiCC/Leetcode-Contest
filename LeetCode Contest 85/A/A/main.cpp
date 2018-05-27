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

#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];
string str;

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
    public:
    int n, m;
    int isValid(int x,int y){
        return (x<n&&y<m);
    }
    int check(int x, int y, vector<vector<int>>& a){
        bool b[11];
        memset(b,false,sizeof(b));
        rep (i,0,2){
            int tot = 0;
            rep (j,0,2){
                if (!isValid(x+i,y+j)){
                    return 0;
                }
                if (b[a[x+i][y+j]]){
                    return false;
                }
                b[a[x+i][y+j]] = true;
                tot+=a[x+i][y+j];
            }
            if (tot!=15){
                return 0;
            }
        }
        rep (j,0,2){
            int tot = 0;
            rep (i,0,2){
                tot += a[x+i][y+j];
            }
            if (tot!=15){
                return 0;
            }
        }
        int tot1 = a[x][y]+a[x+1][y+1]+a[x+2][y+2];
        int tot2 = a[x+2][y]+a[x+1][y+1]+a[x][y+2];
        if (tot1!=15||tot2!=15)
            return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        if (n==0)
            return 0;
        m = grid[0].size();
        int res = 0;
        rep (i,0,n-1){
            rep (j,0,m-1){
                if (check(i,j,grid)){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    
    string zy = s.toGoatLatin("The quick brown fox jumped over the lazy dog");
    cout << zy << endl;
    return 0;
}
