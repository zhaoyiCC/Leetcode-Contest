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

class Solution {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    #define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    int rotatedDigits(int N) {
        int ans = 0;
        int x;
        bool zy;
        rep (j,1,N){
            string t = ""+to_string(j);
            string s = "";
            int i = j;
            zy = true;
            while (i != 0){
                x = i % 10;
//                0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number.
                if ((x == 3) || (x == 4) || (x == 7)){
                    zy = false;
                    break;
                }
                if (x == 0 || x == 1 || x==8)
                    s+=(x+'0');
                else if (x == 2)
                    s+='5';
                else if (x == 5)
                    s+='2';
                else if (x == 6)
                    s+='9';
                else if (x == 9)
                    s+='6';
                i /= 10;
            }
            reverse(s.begin(),s.end());
//            cout << j << " " << s << endl;
            if (zy&&s!=t){
//                cout << j << endl;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    rep (i,10,857){
        cout << i << " " << s.rotatedDigits(i) << endl;
    }
    return 0;
}
