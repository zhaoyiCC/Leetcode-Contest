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
    map<pair<int, int>, int> mp;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        rep (i,0,(int)obstacles.size()-1){
            mp[make_pair(obstacles[i][0], obstacles[i][1])] = 1;
        }
        int x = 0, y = 0, pos = 0;
        int xx[4] = {0,1,0,-1};
        int yy[4] = {1,0,-1,0};
        int ans = 0;
        for (auto i: commands){
            if (i == -1){
                pos = (pos+1)%4;
            }else if (i == -2){
                pos = (pos+3)%4;
            }else{
                rep (j,1,i){
                    if (!mp.count(make_pair(x+xx[pos],y+yy[pos]))){
                        x+=xx[pos],y+=yy[pos];
                        ans = max(ans, x*x+y*y);
                    }else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
    
};

int main(){
    Solution s;
    vector<int> c = {4,-1,4,-2,4};
    vector<int> o1 = {2,4};
    vector<vector<int> > o = {o1};
    cout << s.robotSim(c, o) << endl;
    return 0;
}
