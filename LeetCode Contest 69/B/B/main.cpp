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

typedef long long ll;

#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];

class Solution {
#define rep(i,a,b) for (int i=(a); i <=(b); ++i)
public:
    int g_nCount;
    void mergearray(int a[], int first, int mid, int last, int temp[])
    {
        int i = first, j = mid + 1;
        int m = mid,   n = last;
        int k = 0;
        
        while (i <= m && j <= n) //a[i] 前面的数  a[j] 后面的数
        {
            if (a[i] < a[j])
                temp[k++] = a[i++];
            else
            {
                temp[k++] = a[j++];
                //a[j]和前面每一个数都能组成逆序数对
                g_nCount += m - i + 1;
            }
        }
        
        while (i <= m)
            temp[k++] = a[i++];
        
        while (j <= n)
            temp[k++] = a[j++];
        
        for (i = 0; i < k; i++)
            a[first + i] = temp[i];
    }
    void mergesort(int a[], int first, int last, int temp[])
    {
        if (first < last)
        {
            int mid = (first + last) / 2;
            mergesort(a, first, mid, temp);    //左边有序
            mergesort(a, mid + 1, last, temp); //右边有序
            mergearray(a, first, mid, last, temp); //再将二个有序数列合并
        }
    }
    
    bool MergeSort(int a[], int n)
    {  
        int *p = new int[n];  
        if (p == NULL)  
            return false;  
        mergesort(a, 0, n - 1, p);  
        return true;  
    }
    bool isIdealPermutation(vector<int>& A) {
        size_t n = A.size();
        int ans1 = 0, ans2=0;
        
        
        const int MAXN = (int)A.size();
        int a[MAXN];
//        = {1, 7, 2, 9, 6, 4, 5, 3};
        rep (i,0,MAXN-1){
            a[i] = A[i];
        }
        
        g_nCount = 0;
        MergeSort(a, MAXN);
//        printf("逆序数对为: %d\n", g_nCount);
        ans1 = g_nCount;
        
        rep (i,0,(int)n-2){
            if (A[i] > A[i+1])
                ans2++;
        }
        return (ans1==ans2);
    }
};

class Solution2 {
#define rep(i,a,b) for (int i=(a); i <=(b); ++i)
public:
    bool isIdealPermutation(vector<int>& A) {
        size_t n = A.size();
        int ans1 = 0, ans2=0;
        rep (i,0,(int)n-2){
            rep (j,i+1,n-1){
                if (A[i] > A[j])
                    ans1++;
            }
            if (A[i] > A[i+1])
                ans2++;
        }
        return (ans1>ans2);
    }
};



class Solution3 {
#define rep(i,a,b) for (int i=(a); i <=(b); ++i)
public:
    vector<int> v;
    int ans;
    void mergeSort(int l, int r){
        if (l > r){
            return ;
        }
        if (l==r){
            return ;
        }
        vector<int> vtmp;
        vtmp.resize(r-l+1);
        int mid = (l+r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        
        int i = l, j = mid+1, pos = l;
        while (i <= mid && j <= r){
            if (v[i] > v[j]){
                ans += (mid - i+1);
                vtmp[pos++] = v[j++];
            }else{
                vtmp[pos++] = v[i++];
            }
        }
        rep (k,i,mid){
            vtmp[pos++] = v[k];
        }
        rep (k,j,r){
            vtmp[pos++] = v[k];
        }
        rep (k,l,r){
            v[k] = vtmp[k];
        }
    }
    bool isIdealPermutation(vector<int>& A) {
        size_t n = A.size();
        int ans1 = 0, ans2=0;
        v = A;
        mergeSort(0, (int)n-1);
        ans1 = ans;
        cout << ans << endl;
        rep (i,0,(int)n-2){
            if (A[i] > A[i+1])
                ans2++;
        }
        return (ans1==ans2);
    }
};


int main(){
    vector<int> v={0,3,1,2};
    Solution3 s;
    cout << s.isIdealPermutation(v) << endl;
    return 0;
}
