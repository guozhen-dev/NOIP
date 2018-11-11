/*顾名思义，缩点就是将等价的几个点转化为一个点，点权可累加。那么我们就要用tarjan来求一下哪些点可以缩在一起。
1.dfn和low的含义

   tarjan算法有两个核心数组：dfn和low，同样也需要一个栈，辅助存储强连通分量。dfn是“时间戳”，dfn[i]说明i点在什么时间被遍历的。low[i]是i可回溯到的最早时间戳的点的时间戳(见下面对low值的计算)，默认值为dfn[i]，举个例子：如果i到j有一条路径，j到i也有一条路径，那么就使max(low[i],low[j])=min(low[i],low[j])max(low[i],low[j])=min(low[i],low[j])max(low[i],low[j])=min(low[i],low[j]) 虽然不符合语法，并将路上的点入栈，打上在栈内的标记in。
2.强连通分量的根

   如果一个点i的dfs做完后没有找到能回溯到的点，那么会有dfn[i]==low[i]，i就是i所在强连通分量（树）的根节点。因为树根是i，由dfs的栈性质，从s栈顶到i所在位置均没有强连通分量的根节点，所以将这些点出栈，归为同一个强连通分量++cnt。

   上面的做法也可以直接用并查集并在一起，不过访问时可能会比较麻烦。

   在dfs过程中，如果遍历到一个点k，并且k不在栈中，dfn[k]>0(?k?dfn[k]>0(\Leftrightarrow k \notin dfn[k]>0(?k?这个强连通分量中），则k与这个强连通分量没有关系，因为它被其他分量更新了，而正在处理的强连通分量因为没有被更新，所以两个分量不能在一起（即 不等价）。
3.low数组的求法

   如果dfn[i]!=low[i]，说明i不是其所属强连通分量的根节点。刚进入dfs函数时，将该点压入栈内（与第二点第二句照应）。如果dfs(x)时找到一个点k在栈内，（有向图中）就成环了，这个环就可以被看作是一个点。赋值low[x]=min(low[x],low[x]);即x点可以回溯?\Rightarrow ?x点在k点的强连通分量中，也在环上。不过这个过程还没结束，一个强连通分量可能不止一个环，所以我们还需要继续dfs下去。如果一个点指向的点low值更新了，那么它的low就更新成更小的值，防止误判为“根节点”，需要注意的是：如果找到一个可回溯的点，只更新，不能继续dfs，不然会一直循环下去。在过程结束之后，如果没有更新low的值，说明low是根节点，去到第二点中。
4.其他

    图可能被分为几块，一次dfs不一定能找全所有的强连通分量而导致CE（调用NULL）。所以在dfs时应该枚举开始做的点，一旦dfn==0，就从它开始做。
5.针对这个题

   缩点后，原来的图会被缩成更小的图，强连通分量被视作一个点，这个点的权值是分量中所有点的权值之和。接着枚举每条边，如果边的两端跨越了分量，就把它连上（不能再用原来的图），对入度为0的点做dfs，在近似O(N)的复杂度内可以找出正确答案。
Code:
*/
#include<cstdio>
#include<cstring>
int min(int x,int y){return x<y?x:y;}
struct node
{
    int n;
    node *nxt;
    node (int n)
    {
        this->n=n;
        nxt=NULL;
    }
    node(){nxt==NULL;}
};
node head[10200],*tail[10200];
int dfn[10200],low[10200];
int v[10200],cnt=0;
bool in[10020];//是否在栈中
int s[10020],top=0;//栈
int Index=0;//第几个强连通分量
int y_n[10020],y_v[10020];//分别存储第i个点属于哪个强连通分量，以及存储第i个强连通分量的权值
void dfs(int x)
{
    if(!dfn[x])
    {
        dfn[x]=++cnt;
        low[x]=dfn[x];//新时间戳
    }
    s[++top]=x;//入栈并标记
    in[x]=true;
    node *p=&head[x];
    while(p->nxt!=NULL)
    {
        p=p->nxt;
        if(dfn[p->n]&&!in[p->n])//不在同一个强连通分量
            continue;
        if(in[p->n])
        {
            low[x]=min(low[p->n],low[x]);//更新可回溯的值
            continue;
        }
        dfs(p->n);
        low[x]=min(low[x],low[p->n]);//如果下一个点可回溯则当前点也可回溯
    }
    if(dfn[x]==low[x])//x是强连通分量的根节点，可以退栈了
    {
        y_n[x]=++Index;
        while(s[top]!=x)
        {
            in[s[top]]=false;
            y_n[s[top]]=Index;
            y_v[Index]+=v[s[top]];
            top--;
        }
        in[s[top]]=false;//出栈时要更改状态
        y_n[s[top]]=Index;//存储s[top]属于哪个强连通分量
        y_v[Index]+=v[s[top]];
        top--;
    }
    return;
}
int n,ans=0,maxx=0;
node Head[10020],*Tail[10020];
void Dfs(int x)//在建的新图中找最长点权和的链
{
    node *p=&Head[x];
    while(p->nxt!=NULL)
    {
        p=p->nxt;
        ans+=y_v[p->n];//当前已经走过的点权和
        if(ans>maxx)
            maxx=ans;
        Dfs(p->n);
        ans-=y_v[p->n];
    }
}
void another()//处理新图
{
    int indeg[10020];//入度in-degree
    memset(indeg,0,sizeof(indeg));
    node *p;
    for(int i=1;i<=Index;i++)
        Tail[i]=&Head[i];
    for(int i=1;i<=n;i++)
    {
        p=&head[i];
        while(p->nxt!=NULL)
        {
            p=p->nxt;
            if(y_n[i]!=y_n[p->n])
            {
                Tail[y_n[i]]->nxt=new node(y_n[p->n]);
                Tail[y_n[i]]=Tail[y_n[i]]->nxt;
                indeg[y_n[p->n]]++;
            }
        }
    }
    for(int i=1;i<=Index;i++)
        if(indeg[i]==0)//只有度为0的才找，剪一部分枝
        {
            if(y_v[i]>maxx)
                maxx=y_v[i];
            ans=y_v[i];
            Dfs(i);
        }

}
int main()
{
    memset(in,0,sizeof(in));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    int m,u,V;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        tail[i]=&head[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&V);//建原图
        tail[u]->nxt=new node(V);
        tail[u]=tail[u]->nxt;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i);//缩点

    another();//建新图并处理
    printf("%d\n",maxx);
    return 0;
}
