#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100000
using namespace std;

int n, m;
long long a[N+5], sum[4*N+5], add[4*N+5];

void build(int k, int l, int r);
long long query(int k, int l, int r, int x, int y);
void pushdown(int k, int l, int r, int mid);
void Add(int k, int l, int r, long long v);
void modify(int k, int l, int r, int x, int y, long long v);

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    while(m--)
    {
        int op, x, y, k;
        scanf("%d", &op);
        if(op == 1)//修改
        {
            scanf("%d%d%d", &x, &y, &k);
            modify(1, 1, n, x, y, k);
        }
        else//询问
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}

void build(int k, int l, int r) //线段树编号为k, 目前区间为[l,r]  *(序号为原数列编号)
{//建树
    if(l == r)
    {
        sum[k] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    sum[k] = sum[k<<1] + sum[k<<1|1];
}

long long query(int k, int l, int r, int x, int y) //线段树编号为k, [l,r]为大区间, [x,y]为小区间  *(序号为原数列编号)
{//询问
    if(l >= x && r <= y)
    {
        return sum[k];
    }
    int mid = l + r >> 1;
    long long res = 0;
    pushdown(k, l, r, mid);
    if(x <= mid)
    {
        res += query(k<<1, l, mid, x, y);
    }
    if(y > mid)
    {
        res += query(k<<1|1, mid+1, r, x, y);
    }
    return res;
}

void pushdown(int k, int l, int r, int mid)
{//标记下传
    if(add[k] == 0) return;
    Add(k<<1, l, mid, add[k]);
    Add(k<<1|1, mid+1, r, add[k]);
    add[k] = 0;
}

void Add(int k, int l, int r, long long v)
{//区间+
    add[k] += v;
    sum[k] += v * (r-l+1); //线段树中，该节点及其下面还有r-l+1个节点！ 每个+v, 一共加(r-l+1)个v
}

void modify(int k, int l, int r, int x, int y, long long v)
{
    if(l >= x && r <= y)
    {
        return Add(k, l, r, v);//
    }
    int mid = l + r >> 1;
    pushdown(k, l, r, mid);
    if(x <= mid)
    {
        modify(k<<1, l, mid, x, y, v);
    }
    if(y > mid)
    {
        modify(k<<1|1, mid+1, r, x, y, v);
    }
    sum[k] = sum[k<<1] + sum[k<<1|1];
}
