/*����˼�壬������ǽ��ȼ۵ļ�����ת��Ϊһ���㣬��Ȩ���ۼӡ���ô���Ǿ�Ҫ��tarjan����һ����Щ���������һ��
1.dfn��low�ĺ���

   tarjan�㷨�������������飺dfn��low��ͬ��Ҳ��Ҫһ��ջ�������洢ǿ��ͨ������dfn�ǡ�ʱ�������dfn[i]˵��i����ʲôʱ�䱻�����ġ�low[i]��i�ɻ��ݵ�������ʱ����ĵ��ʱ���(�������lowֵ�ļ���)��Ĭ��ֵΪdfn[i]���ٸ����ӣ����i��j��һ��·����j��iҲ��һ��·������ô��ʹmax(low[i],low[j])=min(low[i],low[j])max(low[i],low[j])=min(low[i],low[j])max(low[i],low[j])=min(low[i],low[j]) ��Ȼ�������﷨������·�ϵĵ���ջ��������ջ�ڵı��in��
2.ǿ��ͨ�����ĸ�

   ���һ����i��dfs�����û���ҵ��ܻ��ݵ��ĵ㣬��ô����dfn[i]==low[i]��i����i����ǿ��ͨ�����������ĸ��ڵ㡣��Ϊ������i����dfs��ջ���ʣ���sջ����i����λ�þ�û��ǿ��ͨ�����ĸ��ڵ㣬���Խ���Щ���ջ����Ϊͬһ��ǿ��ͨ����++cnt��

   ���������Ҳ����ֱ���ò��鼯����һ�𣬲�������ʱ���ܻ�Ƚ��鷳��

   ��dfs�����У����������һ����k������k����ջ�У�dfn[k]>0(?k?dfn[k]>0(\Leftrightarrow k \notin dfn[k]>0(?k?���ǿ��ͨ�����У�����k�����ǿ��ͨ����û�й�ϵ����Ϊ�����������������ˣ������ڴ����ǿ��ͨ������Ϊû�б����£�������������������һ�𣨼� ���ȼۣ���
3.low�������

   ���dfn[i]!=low[i]��˵��i����������ǿ��ͨ�����ĸ��ڵ㡣�ս���dfs����ʱ�����õ�ѹ��ջ�ڣ���ڶ���ڶ�����Ӧ�������dfs(x)ʱ�ҵ�һ����k��ջ�ڣ�������ͼ�У��ͳɻ��ˣ�������Ϳ��Ա�������һ���㡣��ֵlow[x]=min(low[x],low[x]);��x����Ի���?\Rightarrow ?x����k���ǿ��ͨ�����У�Ҳ�ڻ��ϡ�����������̻�û������һ��ǿ��ͨ�������ܲ�ֹһ�������������ǻ���Ҫ����dfs��ȥ�����һ����ָ��ĵ�lowֵ�����ˣ���ô����low�͸��³ɸ�С��ֵ����ֹ����Ϊ�����ڵ㡱����Ҫע����ǣ�����ҵ�һ���ɻ��ݵĵ㣬ֻ���£����ܼ���dfs����Ȼ��һֱѭ����ȥ���ڹ��̽���֮�����û�и���low��ֵ��˵��low�Ǹ��ڵ㣬ȥ���ڶ����С�
4.����

    ͼ���ܱ���Ϊ���飬һ��dfs��һ������ȫ���е�ǿ��ͨ����������CE������NULL����������dfsʱӦ��ö�ٿ�ʼ���ĵ㣬һ��dfn==0���ʹ�����ʼ����
5.��������

   �����ԭ����ͼ�ᱻ���ɸ�С��ͼ��ǿ��ͨ����������һ���㣬������Ȩֵ�Ƿ��������е��Ȩֵ֮�͡�����ö��ÿ���ߣ�����ߵ����˿�Խ�˷������Ͱ������ϣ���������ԭ����ͼ���������Ϊ0�ĵ���dfs���ڽ���O(N)�ĸ��Ӷ��ڿ����ҳ���ȷ�𰸡�
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
bool in[10020];//�Ƿ���ջ��
int s[10020],top=0;//ջ
int Index=0;//�ڼ���ǿ��ͨ����
int y_n[10020],y_v[10020];//�ֱ�洢��i���������ĸ�ǿ��ͨ�������Լ��洢��i��ǿ��ͨ������Ȩֵ
void dfs(int x)
{
    if(!dfn[x])
    {
        dfn[x]=++cnt;
        low[x]=dfn[x];//��ʱ���
    }
    s[++top]=x;//��ջ�����
    in[x]=true;
    node *p=&head[x];
    while(p->nxt!=NULL)
    {
        p=p->nxt;
        if(dfn[p->n]&&!in[p->n])//����ͬһ��ǿ��ͨ����
            continue;
        if(in[p->n])
        {
            low[x]=min(low[p->n],low[x]);//���¿ɻ��ݵ�ֵ
            continue;
        }
        dfs(p->n);
        low[x]=min(low[x],low[p->n]);//�����һ����ɻ�����ǰ��Ҳ�ɻ���
    }
    if(dfn[x]==low[x])//x��ǿ��ͨ�����ĸ��ڵ㣬������ջ��
    {
        y_n[x]=++Index;
        while(s[top]!=x)
        {
            in[s[top]]=false;
            y_n[s[top]]=Index;
            y_v[Index]+=v[s[top]];
            top--;
        }
        in[s[top]]=false;//��ջʱҪ����״̬
        y_n[s[top]]=Index;//�洢s[top]�����ĸ�ǿ��ͨ����
        y_v[Index]+=v[s[top]];
        top--;
    }
    return;
}
int n,ans=0,maxx=0;
node Head[10020],*Tail[10020];
void Dfs(int x)//�ڽ�����ͼ�������Ȩ�͵���
{
    node *p=&Head[x];
    while(p->nxt!=NULL)
    {
        p=p->nxt;
        ans+=y_v[p->n];//��ǰ�Ѿ��߹��ĵ�Ȩ��
        if(ans>maxx)
            maxx=ans;
        Dfs(p->n);
        ans-=y_v[p->n];
    }
}
void another()//������ͼ
{
    int indeg[10020];//���in-degree
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
        if(indeg[i]==0)//ֻ�ж�Ϊ0�Ĳ��ң���һ����֦
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
        scanf("%d%d",&u,&V);//��ԭͼ
        tail[u]->nxt=new node(V);
        tail[u]=tail[u]->nxt;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i);//����

    another();//����ͼ������
    printf("%d\n",maxx);
    return 0;
}
