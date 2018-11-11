#include <bits/stdc++.h>
using namespace std;
int N,M,S;
struct edge {
    int to ;
    int value ;
};
struct edge make_edge(int to , int value){
    struct edge ret;
    ret.to = to ;
    ret.value = value;
    return ret;
}
struct node {
    int dis;
    int index;
};
bool operator < (struct node a , struct node b){
    return a.dis>b.dis;
}
priority_queue <node> pq;
bool vis[100007];
vector<edge> G[200007];
int dis[100007];
void dij(){
    dis[S] = 0 ;
    pq.push((node){0,S});
    vis[S]=1;
    while(!pq.empty()){
        struct node now ;
        now.dis = pq.top().dis;
        now.index = pq.top().index;
        pq.pop();
        for(register int i = 0 ; i < G[now.index].size() ;i++){	
            if ( now.dis + G[now.index][i].value < dis[G[now.index][i].to]){
                dis[G[now.index][i].to] = now.dis + G[now.index][i].value;
                pq.push((node){dis[G[now.index][i].to],G[now.index][i].to});
                vis[G[now.index][i].to]=1;
            }
        }
    }
}
int main(){
    cin >> N>>M>>S;
    S-=1;
    for(int i = 0 ; i < M ; i++ ){
        int tfrom , tto , tvalue;
        cin >> tfrom >> tto >> tvalue;
        G[tfrom-1].push_back(make_edge(tto-1,tvalue));
    }
    for(int i = 0 ; i<sizeof(dis)/sizeof(dis[0]);i++){
        dis[i] = INT_MAX;
    }
    memset(vis,0x00,sizeof(vis));
    dij();
/*	for (int i = 0 ; i < N ; i++){
        cout <<"tangyifei";
        for (int j = 0 ; j < G[i].size() ; j++){
            cout << i << " "<< G[i][j].to << G[i][j].value<<endl;
        }
    }	
*/	
    for (int i = 0 ; i < N ; i++){
        cout << dis[i]<<" ";
    }
    return 0 ;
}

