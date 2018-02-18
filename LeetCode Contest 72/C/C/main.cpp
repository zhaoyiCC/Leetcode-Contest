#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 1005;
int n,k;
int p[maxn];

void Read(){
    scanf("%d%d",&n,&k);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
}

ll Check(int x, int pos){
    int i;
    ll sum = 0;
    for(i=0;i<n;i++){
        sum += (ll)x*p[i]/p[pos];
    }
    return sum;
}

void Solve(){
    int low,mid,high,i;
    for(i=0;i<n;i++){
        low = 1;
        high = p[i]-1;
        while(low<high){
            mid = (low+high)>>1; //(>>1 <=> /2)
            if(Check(mid,i) >= k) high = mid;
            else low = mid+1;
        }
        if(Check(high,i) == k){
            printf("%d/%d\n",high,p[i]);
            printf("%d\n", i);
            break; //QAQ
        }
    }
}

int main(){
    //  freopen("Data.txt","r",stdin);
    Read();
    Solve();
    return 0;
}
