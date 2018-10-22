//
//  main.cpp
//  P3916
//
//  Created by 丁国真 on 2018/10/22.
//  Copyright © 2018 丁国真. All rights reserved.
//
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
int Max_to[N],Min_to[N];
int num_edge,head[N];
struct Edge
{
    int u,v,nxt;
}edge[N];
void add_edge(int u,int v)
{
    edge[++num_edge].u=u;
    edge[num_edge].v=v;
    edge[num_edge].nxt=head[u];
    head[u]=num_edge;
}
void dfs(int u)
{
    for(int i=head[u],v;i;i=edge[i].nxt)
    {
        v=edge[i].v;
        if(Max_to[v])
        {
            Min_to[u]=min(Min_to[u],Min_to[v]);
            Max_to[u]=max(Max_to[u],Max_to[v]);
            continue;
        }
        dfs(v);
        Max_to[u]=max(Max_to[u],Max_to[v]);
        Min_to[u]=min(Min_to[u],Min_to[v]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1,u,v;i<=m;++i)
    {
        cin>>u>>v ;
        add_edge(u,v);
    }
    for(int i=1;i<=n;++i)
        Max_to[i]=Min_to[i]=i;
    for(int i=1;i<=100;++i)
    {
        for(int j=1;j<=n;++j)
            dfs(j);
    }
    for(int i=1;i<=n;++i)
    {
        if(Max_to[i]<Max_to[Min_to[i]])
            Max_to[i]=Max_to[Min_to[i]];
        if(Max_to[i]<Max_to[Max_to[i]])
            Max_to[i]=Max_to[Max_to[i]];
        cout<<Max_to[i]<<" ";
    }
    return 0;
}
