#include<bits/stdc++.h>
#include<time.h>
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define ROF(i,a,b) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define pq priority_queue
using namespace std;
struct game{int t,now;};
int cont[50][3];
game now;
int n,win,cnt[50],wcnt,load;
stack<game> a;
FILE *out;
int main(){
    srand(time(NULL));
    cin>>n;
    while(n--){
        now=(game){0,0};
        while(1){
            if(now.now>=31){
                win=now.t;
                break;
            }
            int next=rand()%3+1;
            a.push((game){now.t,now.now});
            now=(game){!now.t,now.now+next};
        }
        cnt[a.size()]++;
        if(!win) wcnt++;
        while(!a.empty()){
            if(!win) cont[a.top().now][a.top().t]++;
            a.pop();
        }
        if(n%1000000==0) printf("%d\n",++load);
    }
    out=fopen("tmp.txt","w");
    fprintf(out,"%d\n",wcnt);
    FOR(i,0,32) fprintf(out,"%d\n",cnt[i]);
    fprintf(out,"\n");
    FOR(i,0,32) fprintf(out,"%d\n",cont[i][0]);
    fprintf(out,"\n");
    FOR(i,0,32) fprintf(out,"%d\n",cont[i][1]);
    fclose(out);
}
