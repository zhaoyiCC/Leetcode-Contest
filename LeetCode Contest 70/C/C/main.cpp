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
string s1, s2;

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    bool canTransform(string start, string end) {
        int n = (int)start.size();
        if (n==1){
            return start == end;
        }
        int sl = 0, sr = 0, el = 0, er = 0;
        rep (i,0,n-1){
            sl += (start[i] == 'L');
            sr += (start[i] == 'R');
        }
        rep (i,0,n-1){
            el += (end[i] == 'L');
            er += (end[i] == 'R');
        }
        if (sl != el || sr != er)
            return false;
        
        
        rep (i,0,n-1){
            if (start[i] == end[i])
                continue;
            if (start[i] == 'R' && end[i]=='X'){
                if (i == n-1)
                    continue;
                if (!(start[i+1] == 'X' && end[i+1] == 'R')){
                    continue;
                }
                swap(start[i], start[i+1]);
                i++;
                continue;
            }
            if (start[i] == 'X' && end[i]=='L'){
                if (i == n-1)
                    continue;
                if (!(start[i+1] == 'L' && end[i+1] == 'X')){
                    continue;
                }
                swap(start[i], start[i+1]);
                i++;
                continue;
            }
        }
        
        cout << start << endl;
        
        int ix;
        rep (i,0,n-1){
            if (start[i] == end[i])
                continue;
            if (start[i] == 'L' && end[i]=='X'){
                return false;
            }
            
            if (start[i] == 'X' && end[i]=='L'){
                ix = i;
                while (i <= n-1 && start[i] != 'L' && start[i] == 'X'){
                    i++;
                }
                if (i == n)
                    return false;
                if (start[i] == 'R')
                    return false;
                swap(start[ix], start[i]);
                i = ix;
                continue;
            }
        }
        rep2 (i,n-1,0){
            if (start[i] == end[i])
                continue;
            if (start[i] == 'R' && end[i]=='X'){
                return false;
            }
            
            if (start[i] == 'X' && end[i]=='R'){
                ix = i;
                while (i >= 0 && start[i] != 'R' && start[i] == 'X'){
                    i--;
                }
                if (i == -1)
                    return false;
                if (start[i] == 'L')
                    return false;
                swap(start[ix], start[i]);
                i = ix;
                continue;
            }

        }
        return true;
    }
};

int main(){

    cin >> s1 >> s2;
    Solution s;
    cout << s.canTransform(s1, s2);
    
    return 0;
}
