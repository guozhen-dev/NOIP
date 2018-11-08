#include<bits/stdc++.h>
using namespace std;
 
const int N=4e6+5;
int n,m,d[N],f[N],ff[2005][2005];
int cnt,he[N],to[N],nxt[N],w[N];
bool fl[N];
 
struct NA{
    int id,x;
};
bool operator >(NA i,NA j)
{
    return i.x>j.x;
}
priority_queue<NA,vector<NA>,greater<NA> >q;
 
inline void add(int u,int v,int k)
{
    to[++cnt]=v,nxt[cnt]=he[u];
    w[cnt]=k,he[u]=cnt;
}
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        if(!ff[u][v]) ff[u][v]=k;	
        	else ff[u][v]=min(ff[u][v],k);
    }	
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		if(ff[i][j]) add(i,j,ff[i][j]);
 
    for(int i=1;i<=n;i++) d[i]=2e9;
    q.push((NA){1,d[1]=0}); f[1]=1;
    while(!q.empty())
    {
        while(!q.empty()&&fl[q.top().id]) q.pop();
        if(q.empty()) break;
        int u=q.top().id;
        fl[u]=1,q.pop();
        for(int e=he[u];e;e=nxt[e])
        {
            int v=to[e];
            if(d[v]==d[u]+w[e]) f[v]+=f[u];
            if(!fl[v])
                if(d[v]>d[u]+w[e])
                    q.push((NA){v,d[v]=d[u]+w[e]}),f[v]=f[u];
        }
    }
    if(d[n]==2e9) puts("No answer");
        else printf("%d %d\n",d[n],f[n]);
    return 0;
}
