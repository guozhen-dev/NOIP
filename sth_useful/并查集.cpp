#include <bits/stdc++.h>
 
using namespace std;
const int maxn=1e5+7;
int father[maxn];
 
int Find(int x)
{
	if(father[x]==x) return  x;
	else return father[x]=Find(father[x]);
}
 
void merge(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
        father[fx]=fy;
}
 
bool judge(int x,int y)
{
    return Find(x)==Find(y);
}
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        join(a,b);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",Find(i));
    printf("\n");
    return 0;
}
