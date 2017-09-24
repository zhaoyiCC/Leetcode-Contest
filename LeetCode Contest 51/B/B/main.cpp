//
//  main.cpp
//  B
//
//  Created by ohazyi on 2017/9/24.
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
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

    int zy[6],a,b,c,d,aaa[6],x,y,tim;
    vector<int> v;
    int ans = 1e9;
    bool find(){
        int res, gap, xxx, yyy;
        xxx =10*aaa[1]+aaa[2];
        yyy=10*aaa[3]+aaa[4];
        if (xxx >24||yyy>=60)
            return false;
        res = 60*(10*aaa[1]+aaa[2])+10*aaa[3]+aaa[4];
        gap = res - tim;
        if (gap == 0)
            return false;
        if (gap < 0){
            gap = 24*60+gap;
        }
        
        if (gap < ans){
            ans = gap;
            rep (i,1,4)
                zy[i]=aaa[i];
            return true;
        }
        return false;
    }
    void dfs(int k)
    {
        if (k > 4){
            find();
          return ;
        }
        rep (i,0,3){
            aaa[k] = v[i];
            dfs(k+1);
        }
    }string nextClosestTime(string time) {
        a = time[0]-'0';
        b = time[1]-'0';
        c = time[3]-'0';
        d = time[4]-'0';
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        x = 10*a+b;
        y = 10*c+d;
        tim = 60*x+y;
        dfs(1);
        string res ="";
        res += zy[1]+'0';
        res+=zy[2]+'0';
        res+=":";
        res+=zy[3]+'0';
        res+=zy[4]+'0';
        if (ans==1e9)
            
            return time;
        return res;
    }
};

int main() {

    string str;
    cin >> str;

    string ans;
    Solution s;
    ans = s.nextClosestTime(str);
    cout << ans << endl;

    return 0;
}
