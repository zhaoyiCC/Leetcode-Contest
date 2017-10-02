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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, a[N];
class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    int repeatedStringMatch(string A, string B) {
        int l1, l2;
        l1 = A.size();
        l2 = B.size();
        int n = max(l1,l2);
        string s = A;
        string::size_type position;
        
        int limit = 1e9;
        rep (i,0,n+1){
            if (s.size() >= B.size()){
                position = s.find(B);
                if (position != A.npos){
                    return i+1;
                }
            }
            if (limit==0)
                return -1;
            if (s.size()>B.size())
                limit = 0;
            s+=A;
            
        }
        return -1;
    }
};

class Solution2 {
public:
    int f[150000];
    int l1, l2;
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    void getfill(int tim,string s)
    {
        
//        for(int i=1;i<s.size();i++)
        for(int i=tim*l1+1;i<s.size();i++)
        {
            int j=f[i];
            while(j && s[i]!=s[j])
                j=f[j];
            f[i+1]=(s[i]==s[j])?j+1:0;
        }
    }
    int find(int tim, string a,string s)
    {
        int ans=0;
        getfill(tim, s);
        int j=0;
        //for(int i=0;i<a.size();i++)
        for(int i=0;i<a.size();i++)
        {
            while(j && a[i]!=s[j])
                j=f[j];
            if(a[i]==s[j])
                j++;
            if(j==s.size()){
                ans++;
            }
        }
        return ans;
    }

    
    int repeatedStringMatch(string A, string B) {
        
        l1 = A.size();
        l2 = B.size();
        int n = max(l1,l2);
        string s = A;
        string::size_type position;
        memset(f,0,sizeof(f));  //根据其前一个字母得到
        
        bool b[3000];
        memset(b,false,sizeof(b));
        rep (i,0,l1-1)
            b[A[i]] = true;
        rep (i,0,l2-1)
        if (!b[B[i]]){
            return -1;
        }
        rep (i,0,n+1){
            //position = s.find(B);
            //if (position != A.npos)
            int ans=find(i, s,B);//长的在前面，短的在后面
            if (ans!=0)
            {
                return i+1;
            }
            s+=A;
        }
        return -1;
    }
};

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    string::size_type position;
    position = s1.find("day");//find函数返回day在str1中第一次出现的下标位置
    
    if (position!=s1.npos)//如果没找到，返回npos，这是一个很大的值
    {
        cout << position << endl;
    }


    ans = 0;
    Solution s;
    ans = s.repeatedStringMatch(s1, s2);
    cout << ans << endl;

    return 0;
}
