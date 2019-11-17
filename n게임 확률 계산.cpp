#include<bits/stdc++.h>
#include<time.h>
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define ROF(i,a,b) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define pq priority_queue
using namespace std;
int n;
long double dp[100010][3],th;
FILE *out;
int main(){
    cin>>n;
    dp[0][0]=1.0l;
    dp[0][1]=0.0l;
    th=(1.0l/3.0l);
    out=fopen("tmf.txt","w");
    FOR(i,1,n){
        if(i-2<0) dp[i][0]=dp[i-1][1],dp[i][1]=dp[i-1][0];
        else if(i-3<0) dp[i][0]=0.5l*(dp[i-1][1]+dp[i-2][1]),dp[i][1]=0.5l*(dp[i-1][0]+dp[i-2][0]);
        else dp[i][0]=th*(dp[i-1][1]+dp[i-2][1]+dp[i-3][1]),dp[i][1]=th*(dp[i-1][0]+dp[i-2][0]+dp[i-3][0]);
        fprintf(out,"%d : %.15lf\n",i,dp[i][0]);
    }
    fclose(out);
}
