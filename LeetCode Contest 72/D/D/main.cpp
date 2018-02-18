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

//class Solution2 {
//public:
//#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
//#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
//    struct mynode{
//        int x,y;
//    };
//    static bool cmp(mynode& a, mynode& b){
//        return (a.x*b.y)<(b.x*a.y);
//    }
//    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
//        int n = (int)A.size();
//        vector<mynode> v;
//        v.reserve((n+1)*(n+1));
//        rep (i,0,n-1){
//            rep (j,i+1,n-1){
//                mynode t = {A[i], A[j]}; //node(A[i], A[j])
//                //v.push_back(node{A[i], A[j]});//emplace_back
//                v.emplace_back(t);
//            }
//        }
//        sort(v.begin(), v.end(), cmp);
//        for (auto i: v){
//            cout << i.x << " " << i.y << endl;
//        }
//        return {v[K-1].x,v[K-1].y};
//    }
//};
//struct mynode{
//    int x,y;
//}v[4000010];
//class Solution3 {
//public:
//#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
//#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
//    static bool cmp(mynode& a, mynode& b){
//        return (a.x*b.y)<(b.x*a.y);
//    }
//    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
//        int n = (int)A.size();
//        int tot = 0;
//        rep (i,0,n-1){
//            rep (j,i+1,n-1){
//                v[++tot].x = A[i];// = mynode{A[i], A[j]};
//                v[tot].y = A[j];
//            }
//        }
//        sort(v+1, v+tot+1, cmp);
//        return {v[K].x,v[K].y};
//    }
//};
//double vals[4000010];
//class Solution4{
//#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
//public:
//    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
//        int n = (int)A.size();
//        int tot = 0;
//        rep (i,0,n-1){
//            rep (j,i+1,n-1){
//                vals[tot++] = 1.0*A[i]/A[j];
//            }
//        }
//        rep (i,0,tot-1)
//            cout << vals[i] << " ";
//        cout << endl;
//        nth_element(vals, vals+K-1, vals+tot);
//        rep (i,0,tot-1)
//            cout << vals[i] << " ";
//        cout << endl;
//        rep (i,0,n-1){
//            rep (j,i+1,n-1){
//                if (1.0*A[i]/A[j] == vals[K-1]){
//                    return {A[i], A[j]};
//                }
//            }
//        }
//        return {0,0};
//    }
//};

vector<int> aaa;
struct T{
    int x, y;
    bool operator < (T t) const{
        return x<t.x;
    }
//    bool operator < (T t) const {
//        return 1.0*aaa[x]/aaa[y] > 1.0*aaa[t.x]/aaa[t.y];
//    }
//    bool operator > (T t) const {
//        return 1.0*aaa[x]/aaa[y] < 1.0*aaa[t.x]/aaa[t.y];
//    }
};
bool cmp(T& a, T& b){
    return a.x < b.x;
}
priority_queue<T> v;
class Solution{
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        aaa = A;
        int n = (int)A.size();
        while (!v.empty()) //！！！竟然必须得加上这个初始化，否则LeetCode会WA
            v.pop();
        rep (i,0,n-2){
            v.push(T{i,n-1});
        }
        rep (i,1,K-1){
            T now = v.top();
            int xx = now.x;
            int yy = now.y;
            if (yy!=0){
                v.push(T{xx,yy-1});
            }
            v.pop();
        }
        T now = v.top();
        return {A[now.x], A[now.y]};
    }
};

int main(){
    vector<int> v;
    v={1,7};
    Solution s;
    vector<int> ans = s.kthSmallestPrimeFraction(v, 1);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
