//如果是乘法，那么加法的标记也要更新
//加法是+=数字*区间长度
//乘法是直接乘
//先更新乘法，再更新加法，以保证正确性
//最后不要忘了更新结点的权值
//代码极其简洁，77line没有压行，1.6k大小，极易懂
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,m,mod,num,typ,x,y,k,ans;
struct nod
{
    ll l,r,w,add,mul;
}s[1000005];//四倍空间以上
ll build(ll x,ll L,ll R)
{
    s[x]=nod{L,R,0,0,1};//构造函数，用来让代码更简洁
    if(L==R)
    {
        scanf("%lld",&num);
        return s[x].w=num%mod;//特色建树，到了叶子节点时再输入，然后传上去
    }
    ll mid=(L+R)/2;
    return s[x].w=(build(x*2,L,mid)+build(x*2+1,mid+1,R))%mod;
}
void down(ll x)

{//具体的标记下传

    s[x*2].add=(s[x].add+s[x*2].add*s[x].mul)%mod;
    s[x*2+1].add=(s[x].add+s[x*2+1].add*s[x].mul)%mod;
    s[x*2].mul=(s[x*2].mul*s[x].mul)%mod;
    s[x*2+1].mul=(s[x*2+1].mul*s[x].mul)%mod;
    s[x*2].w=(s[x*2].w*s[x].mul+s[x].add*(s[x*2].r-s[x*2].l+1))%mod;
    s[x*2+1].w=(s[x*2+1].w*s[x].mul+s[x].add*(s[x*2+1].r-s[x*2+1].l+1))%mod;
    s[x].add=0;
    s[x].mul=1;
}
ll query(ll x,ll L,ll R)
{
    down(x);
    if(s[x].l>=L&&s[x].r<=R)//包含的话直接返回
        return s[x].w%mod;
    ll mid=(s[x].l+s[x].r)/2;//哪边有询问就加上哪边的询问值
    return ((L<=mid?query(x*2,L,R):0)+(R>mid?query(x*2+1,L,R):0))%mod;
}
void update(ll x,ll v,ll typ,ll L,ll R)
{
    down(x);
    if(typ==1&&s[x].l>=L&&s[x].r<=R)//包含关系
    {
        s[x].mul=(s[x].mul*v)%mod;
        s[x].add=(s[x].add*v)%mod;
        s[x].w=(s[x].w*s[x].mul)%mod;//先乘再加
        return;
    }
    if(typ==2&&s[x].l>=L&&s[x].r<=R)
    {
        s[x].add=(s[x].add+v)%mod;
        s[x].w=(s[x].w+s[x].add*(s[x].r-s[x].l+1))%mod;
        return;
    }
    ll mid=(s[x].l+s[x].r)/2;
    if(L<=mid)
        update(x*2,v,typ,L,R);
    if(R>mid)
        update(x*2+1,v,typ,L,R);
    s[x].w=s[x*2].w+s[x*2+1].w;//最后更新父亲节点
}
main()
{
    scanf("%lld%lld%lld",&n,&m,&mod);
    build(1,1,n);
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&typ,&x,&y);
        if(typ!=3)
        {
            scanf("%lld",&k);
            update(1,k,typ,x,y);
        }
        else
            printf("%lld\n",query(1,x,y));
    }
}
