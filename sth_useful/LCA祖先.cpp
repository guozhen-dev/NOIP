#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<vector>
#define maxn 500500
using namespace std;
///隶属邻接表 
struct Edge{                    //邻接表的结构体 
    int from,to;
}edges[2*maxn];                 //边要乘2，因为是无向图 ； 
int first[maxn],next[2*maxn];   //同理； 
int read(){                        //读入优化，可以照着这个模板来写，这个还算写的比较好看。 
    int re=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9'){ 
        re=re*10+ch-'0'; 
        ch=getchar();
    }
    return re;
}
///////////////////////////////////////////////
///全局变量 
int n,m;
int root;
int height[maxn];
float log2n;
///////////////////////////////////////////////////////
///隶属LCA的全局变量 
int f[maxn][20];// 
int have[maxn];                           //have，有没有找过，这都是套路 。 
void dfs(int u,int h){                 //u代表点的标号，h代表高度。 
    int v;
    height[u]=h;
    for(int i=1;i<=log2n;i++) {
        if(h<=(1<<i)) break;              //由于i是从小到大计算的，故（1<<i）>=h 时可直接退出。请务必想清楚是<=  还是=。
        f[u][i] = f[ f[u][i-1] ][i-1]; //动规计算。同样也是一切倍增算法的核心。 
    }
    int k=first[u];
    while(k!=-1){
        v=edges[k].to;
        if(!have[v]) {
            have[v]=1;        
            f[v][0]=u;                 //将要找的下一个点的父节点标为当前处理的节点u。 
            dfs(v,h+1);
        }
        k=next[k];
    }
}
int require_LCA(int a,int b){
    int da=height[a],db=height[b];
//第一步，将a，b两点移到同样的高度，只动高度大的那个点而不动高度小的那个点。 
    if(da!=db) {
        if(da<db){                   //保证a的高度是大于b的高度的。 
            swap(a,b);
            swap(da,db);
        }
        int d=da-db;
        for(int i=0;i<=log2n;i++) 
            if( (1<<i) & d) a=f[a][i]; //这里的位运算可以减少代码量
                                       //考虑到d是一个定值，而（1<<i）在二进制中只有第（i+1）位是1； 
                                       //那么d与（1<<i）如果某一位为1，那么表示可以向上移动， 
                                       //如果此时不移动，那么i增大了后就无法使height[a]==height[b]了 
    }
//第二步,找到某个位置i，在这个位置时，f[a][i]!=f[b][i],但再向上移动一步，a，b相同了 
//从log2n开始从大到小枚举i，如果超过了a，b的高度，则令i继续减小
//如果没有超过a，b的高度，那么就判断移动了后会不会让a==b，
//是，则i继续减小，否则，令此时的a=f[a][i],b=f[b][i]; 
    if(a==b) return b;
    int i=0;
    for(i=log2n;i>=0;i--) {
        if(height[ f[a][i] ]<0) continue;
        if( f[a][i]==f[b][i] ) continue;
        else a=f[a][i],b=f[b][i];        //顺便一提，在第二步任何地方没有break；
                                       //我就是因为在这里写了一个break，然后找了我两个小时啊。 
    }    
    return f[a][0];
}
/////////////////////////////////
///据说从主函数开始阅读是个好习惯。 
int main(){
//    freopen("in2.txt","r",stdin);
    n=read();m=read();root=read();
    memset(first,-1,sizeof(first));
    memset(next,-1,sizeof(next));
    int s,t;
    int dsd=2*(n-1);
    for(int i=1;i<=dsd;i+=2) {
        s=read();t=read();      //读入优化。 
        edges[i].from=s;
        edges[i].to=t;
        edges[i+1].from=t;
        edges[i+1].to=s;
        next[i]=first[s];
        first[s]=i;
        next[i+1]=first[t];
        first[t]=i+1;
    }
    // 以上是邻接表，在此不再赘述。 
    log2n=log(n)/log(2)+1;        //C++计算log是自然对数，我们要用的以2为底的对数，故要除以log(2); 
                                  //对无理数加上1或是0.5是个好习惯，可以减小误差； 
    memset(have,0,sizeof(have));
    memset(height,0,sizeof(height));
    memset(f,-1,sizeof(f));
    have[root]=1;                //fa[][]和height[]要在dfs理进行计算，不然根本找不到某个非根节点的父亲是谁; 
    dfs(root,1);                
    for(int i=1;i<=n;i++){
        for(int j=0;j<=log2n;j++) {
            if(height[i] <=(1<<j) ) break;
        }
    }
    for(int i=0;i<m;i++) {      //应对要求进行求解。 
        s=read();t=read();
        int y=require_LCA(s,t);
        printf("%d\n",y);
    }
    return 0;
}
