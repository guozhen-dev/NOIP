//����ǳ˷�����ô�ӷ��ı��ҲҪ����
//�ӷ���+=����*���䳤��
//�˷���ֱ�ӳ�
//�ȸ��³˷����ٸ��¼ӷ����Ա�֤��ȷ��
//���Ҫ���˸��½���Ȩֵ
//���뼫���࣬77lineû��ѹ�У�1.6k��С�����׶�
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,m,mod,num,typ,x,y,k,ans;
struct nod
{
    ll l,r,w,add,mul;
}s[1000005];//�ı��ռ�����
ll build(ll x,ll L,ll R)
{
    s[x]=nod{L,R,0,0,1};//���캯���������ô�������
    if(L==R)
    {
        scanf("%lld",&num);
        return s[x].w=num%mod;//��ɫ����������Ҷ�ӽڵ�ʱ�����룬Ȼ����ȥ
    }
    ll mid=(L+R)/2;
    return s[x].w=(build(x*2,L,mid)+build(x*2+1,mid+1,R))%mod;
}
void down(ll x)

{//����ı���´�

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
    if(s[x].l>=L&&s[x].r<=R)//�����Ļ�ֱ�ӷ���
        return s[x].w%mod;
    ll mid=(s[x].l+s[x].r)/2;//�ı���ѯ�ʾͼ����ıߵ�ѯ��ֵ
    return ((L<=mid?query(x*2,L,R):0)+(R>mid?query(x*2+1,L,R):0))%mod;
}
void update(ll x,ll v,ll typ,ll L,ll R)
{
    down(x);
    if(typ==1&&s[x].l>=L&&s[x].r<=R)//������ϵ
    {
        s[x].mul=(s[x].mul*v)%mod;
        s[x].add=(s[x].add*v)%mod;
        s[x].w=(s[x].w*s[x].mul)%mod;//�ȳ��ټ�
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
    s[x].w=s[x*2].w+s[x*2+1].w;//�����¸��׽ڵ�
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
