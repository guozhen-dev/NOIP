#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100007;
struct edge{
    int to ;
    int value;
};
vector<edge> G[MAX_N];
queue<int> q;
void add_edge(int x , int y , int v){
    struct edge ret;
    ret.to=y;
    ret.value=v;
    G[x].push_back(ret);
}
int M,N,S;
int dis[MAX_N];

int main(){
    for(int i = 0 ; i<sizeof(dis)/sizeof(dis[0]);i++){
        dis[i]=INT_MAX;
    }
    cin >> N >> M >> S;
    for (int i = 1 ; i <= M ; i++){
        int tx , ty , tv;
        cin >> tx >> ty >> tv;
        add_edge(tx, ty ,tv);
    }
    dis[S]=0;
    bool vis[MAX_N]={0,};
    q.push(S);
    vis[S]=1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        vis[current]=0;
        for(int i = 0 ; i < G[current].size() ; i++){
            if(dis[G[current][i].to] > dis[current]+G[current][i].value){
                dis[G[current][i].to]=dis[current]+G[current][i].value;
                if(!vis[G[current][i].to]) {
                    q.push(G[current][i].to);
                    vis[G[current][i].to]=1;
                }
            }
        }
    }
    for(int i = 1 ; i <= N ; i++){
        cout << dis[i] <<" ";
    }
    return 0;
}

