//
//  main.cpp
//  B
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
#include <cstdlib>

typedef long long ll;

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> a;
        vector<int> last ={4,3,2,1,5,0};// {3,4,2,1,5,0};
//        last.resize(6);
        
//        last[0] = board[0][0];
//        last[1] = board[0][1];
//        last[2] = board[0][2];
//        last[3] = board[1][0];
//        last[4] = board[1][1];
//        last[5] = board[1][2];
        
        a.resize(6);
        a[0] = board[0][0];
        a[1] = board[0][1];
        a[2] = board[0][2];
        a[3] = board[1][0];
        a[4] = board[1][1];
        a[5] = board[1][2];
        vector<int> v = {1,2,3,4,5,0};
        map<vector<int>, int> mp;
        vector<vector<int>> vvv, vnew;
        vnew.push_back(v);
        mp[v] = 0;
        vector<int> vx = {0,1,3,4,0,1,2};
        vector<int> vy = {1,2,4,5,3,4,5};
        bool flag = true;
        while (true){
            vvv=vnew;
            vnew.clear();
            for (auto x: vvv){
                int now = mp[x];
                vector<int> tmp;
                rep (j,0,(int)vx.size()-1){
                    tmp = x;
                    int tx = vx[j];
                    int ty = vy[j];
                    if (tmp[tx]!=0 && tmp[ty]!=0)
                        continue;
                    swap(tmp[tx], tmp[ty]);
                    if (mp[tmp] == 0){
//                        if (tmp == last){
//                            rep (k,0,5){
//                                
//                                cout << x[k];
//                                if (k!=5)
//                                    cout << ",";
//                            }
//                            cout << endl;
//                        }
                        mp[tmp] = now+1;
                        vnew.push_back(tmp);
                    }else if (now+1<mp[tmp]){
                        
                        mp[tmp] = now+1;
                        vnew.push_back(tmp);
                    }
                }
            }
            if (vnew.size() == 0)
                break;
            flag = false;
        }
        
        if (mp[a] == 0 && a != v)
            return -1;
        return mp[a];
    }
};


int main(){
    
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,0};
    vector<vector<int>> a;
    a.push_back(v1);
    a.push_back(v2);
    Solution s;
    cout << s.slidingPuzzle(a) << endl;
    return 0;
}
