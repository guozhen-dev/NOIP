#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<vector>
#define maxn 500500
using namespace std;
///�����ڽӱ� 
struct Edge{                    //�ڽӱ�Ľṹ�� 
    int from,to;
}edges[2*maxn];                 //��Ҫ��2����Ϊ������ͼ �� 
int first[maxn],next[2*maxn];   //ͬ�� 
int read(){                        //�����Ż��������������ģ����д���������д�ıȽϺÿ��� 
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
///ȫ�ֱ��� 
int n,m;
int root;
int height[maxn];
float log2n;
///////////////////////////////////////////////////////
///����LCA��ȫ�ֱ��� 
int f[maxn][20];// 
int have[maxn];                           //have����û���ҹ����ⶼ����· �� 
void dfs(int u,int h){                 //u�����ı�ţ�h����߶ȡ� 
    int v;
    height[u]=h;
    for(int i=1;i<=log2n;i++) {
        if(h<=(1<<i)) break;              //����i�Ǵ�С�������ģ��ʣ�1<<i��>=h ʱ��ֱ���˳���������������<=  ����=��
        f[u][i] = f[ f[u][i-1] ][i-1]; //������㡣ͬ��Ҳ��һ�б����㷨�ĺ��ġ� 
    }
    int k=first[u];
    while(k!=-1){
        v=edges[k].to;
        if(!have[v]) {
            have[v]=1;        
            f[v][0]=u;                 //��Ҫ�ҵ���һ����ĸ��ڵ��Ϊ��ǰ����Ľڵ�u�� 
            dfs(v,h+1);
        }
        k=next[k];
    }
}
int require_LCA(int a,int b){
    int da=height[a],db=height[b];
//��һ������a��b�����Ƶ�ͬ���ĸ߶ȣ�ֻ���߶ȴ���Ǹ���������߶�С���Ǹ��㡣 
    if(da!=db) {
        if(da<db){                   //��֤a�ĸ߶��Ǵ���b�ĸ߶ȵġ� 
            swap(a,b);
            swap(da,db);
        }
        int d=da-db;
        for(int i=0;i<=log2n;i++) 
            if( (1<<i) & d) a=f[a][i]; //�����λ������Լ��ٴ�����
                                       //���ǵ�d��һ����ֵ������1<<i���ڶ�������ֻ�еڣ�i+1��λ��1�� 
                                       //��ôd�루1<<i�����ĳһλΪ1����ô��ʾ���������ƶ��� 
                                       //�����ʱ���ƶ�����ôi�����˺���޷�ʹheight[a]==height[b]�� 
    }
//�ڶ���,�ҵ�ĳ��λ��i�������λ��ʱ��f[a][i]!=f[b][i],���������ƶ�һ����a��b��ͬ�� 
//��log2n��ʼ�Ӵ�Сö��i�����������a��b�ĸ߶ȣ�����i������С
//���û�г���a��b�ĸ߶ȣ���ô���ж��ƶ��˺�᲻����a==b��
//�ǣ���i������С���������ʱ��a=f[a][i],b=f[b][i]; 
    if(a==b) return b;
    int i=0;
    for(i=log2n;i>=0;i--) {
        if(height[ f[a][i] ]<0) continue;
        if( f[a][i]==f[b][i] ) continue;
        else a=f[a][i],b=f[b][i];        //˳��һ�ᣬ�ڵڶ����κεط�û��break��
                                       //�Ҿ�����Ϊ������д��һ��break��Ȼ������������Сʱ���� 
    }    
    return f[a][0];
}
/////////////////////////////////
///��˵����������ʼ�Ķ��Ǹ���ϰ�ߡ� 
int main(){
//    freopen("in2.txt","r",stdin);
    n=read();m=read();root=read();
    memset(first,-1,sizeof(first));
    memset(next,-1,sizeof(next));
    int s,t;
    int dsd=2*(n-1);
    for(int i=1;i<=dsd;i+=2) {
        s=read();t=read();      //�����Ż��� 
        edges[i].from=s;
        edges[i].to=t;
        edges[i+1].from=t;
        edges[i+1].to=s;
        next[i]=first[s];
        first[s]=i;
        next[i+1]=first[t];
        first[t]=i+1;
    }
    // �������ڽӱ��ڴ˲���׸���� 
    log2n=log(n)/log(2)+1;        //C++����log����Ȼ����������Ҫ�õ���2Ϊ�׵Ķ�������Ҫ����log(2); 
                                  //������������1����0.5�Ǹ���ϰ�ߣ����Լ�С�� 
    memset(have,0,sizeof(have));
    memset(height,0,sizeof(height));
    memset(f,-1,sizeof(f));
    have[root]=1;                //fa[][]��height[]Ҫ��dfs����м��㣬��Ȼ�����Ҳ���ĳ���Ǹ��ڵ�ĸ�����˭; 
    dfs(root,1);                
    for(int i=1;i<=n;i++){
        for(int j=0;j<=log2n;j++) {
            if(height[i] <=(1<<j) ) break;
        }
    }
    for(int i=0;i<m;i++) {      //Ӧ��Ҫ�������⡣ 
        s=read();t=read();
        int y=require_LCA(s,t);
        printf("%d\n",y);
    }
    return 0;
}
