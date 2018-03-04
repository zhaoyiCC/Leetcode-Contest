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
    map<vector<string>, int> mp;
    vector<string> b;
    int a[4][4];
    bool zy = false;
    int check2(){
        rep (j,1,1){
            rep (i,0,2){
                if (a[i][0] == j && a[i][1]==j && a[i][2] == j){
                    return j;
                }
            }
        }
        rep (j,1,1){
            rep (i,0,2){
                if (a[0][i] == j && a[1][i]==j && a[2][i] == j){
                    return j;
                }
            }
        }
        rep (j,1,1){
            if (a[0][0] == j && a[1][1]==j && a[2][2] == j){
                return j;
            }
        }
        rep (j,1,1){
            if (a[0][2] == j && a[1][1]==j && a[2][0] == j){
                return j;
            }
        }
        rep (i,0,2){
            rep (j,0,2){
                if (a[i][j] == -1){
                    return -1;
                }
            }
        }
        return 2;
    }
    int check(){
        rep (j,0,1){
            rep (i,0,2){
                if (a[i][0] == j && a[i][1]==j && a[i][2] == j){
                    return j;
                }
            }
        }
        rep (j,0,1){
            rep (i,0,2){
                if (a[0][i] == j && a[1][i]==j && a[2][i] == j){
                    return j;
                }
            }
        }
        rep (j,0,1){
            if (a[0][0] == j && a[1][1]==j && a[2][2] == j){
                return j;
            }
        }
        rep (j,0,1){
            if (a[0][2] == j && a[1][1]==j && a[2][0] == j){
                return j;
            }
        }
        rep (i,0,2){
            rep (j,0,2){
                if (a[i][j] == -1){
                    return -1;
                }
            }
        }
        return 2;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int cnt0=0, cnt1=0;
        memset(a,-1,sizeof(a));
        rep (i,0,2){
            rep (j,0,2){
                if (board[i][j]=='O')
                    a[i][j] = 0;
                else if (board[i][j]=='X')
                    a[i][j] = 1;
                
                cnt0+=board[i][j]=='O';
                cnt1+=board[i][j]=='X';
            }
        }
        if (cnt1>cnt0+1)
            return false;
        if (cnt0>cnt1)
            return false;
        if (check()==-1&&check2()==-1)
            return false;
        if (cnt1==cnt0+1 && check()==0)
            return false;
        if (cnt1==cnt0 && check2()==1)
            return false;
        return true;
    }
};

int main(){
    Solution s;
    string v1,v2,v3;
    vector<string> v;
    v1="XXX";
    v2="   ";
    v3="OOO";
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout << s.validTicTacToe(v) << endl;
    return 0;
}
