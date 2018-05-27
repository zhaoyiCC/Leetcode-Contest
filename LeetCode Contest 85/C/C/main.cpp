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

#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)

using namespace std;

const ll N = 10010;
ll ans, n , m, k, a[N];
string str;

typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)
class Solution {
public:
    ll x[10100];
    ll MAXNUM = (1LL<<31LL)-1LL;
    bool check(string s){
        if (s=="0")
            return true;
        if (s[0]=='0'&&s.size()>1)
            return false;
        return true;
    }
    vector<int> splitIntoFibonacci(string s) {
        ll n = s.size();
        vector<int> ans;
        if (n==0){
            return ans;
        }
        string s1, s2;
        ll k, pos;
        rep (i,0,min(11LL,n-1)){ //0..i, i+1,j, j+1..n-1
            rep (j,i+1,min(i+1+11,n-1)){
                if (i==2&&j==5){
                    ll fuck=1;
                    fuck++;
                }
                ans.clear();
                s1 = s.substr(0, i+1);
                s2 = s.substr(i+1, j-i);
                if (!check(s1)||!check(s2)){
                    continue;
                }
                x[1] = atoll(s1.c_str());
                x[2] = atoll(s2.c_str());
                if (x[1]>MAXNUM||x[2]>MAXNUM){
                    continue;
                }
                ans.push_back(x[1]);
                ans.push_back(x[2]);
                k = j+1;
                pos = 2;
                bool zy=true;
                while (k < n){
                    pos++;
                    x[pos] = x[pos-1] + x[pos-2];
                    if (x[pos]>MAX){
                        int kk;
                        kk=1;
                    }
                    if (x[pos]>MAXNUM){
                        zy=false;
                        break;
                    }
                    string tt = to_string(x[pos]);
                    ll l = tt.size();
                    if (k+l>n){
                        zy = false;
                        break;
                    }
                    string ss = s.substr(k, l);
                    cout << ss << endl;
                    if (ss != tt){
                        zy = false;
                        break;
                    }
                    ans.push_back(x[pos]);
                    k = k+l;
                }
                if (k==n&&zy&&ans.size()>2){
                    return ans;
                }
            }
        }
        ans.clear();
        
        return ans;
    }
};

int main(){
    ll x =atoll("123456579");
    cout << atoll("217483648")<< endl;
    Solution s;
    vector<int> v = s.splitIntoFibonacci("3611537383985343591834441270352104793375145479938855071433500231900737525076071514982402115895535257195564161509167334647108949738176284385285234123461518508746752631120827113919550237703163294909");
    for (auto i: v){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
