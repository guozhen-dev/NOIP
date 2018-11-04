#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#define RI register int
const int sz = 100010;
inline void read(int &x)
{
    x=0;bool fl=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {if(c=='-') fl=1;c=getchar();}
    while(c>='0'&&c<='9')
    {x=x*10+c-'0';c=getchar();}
    if(fl) x*=-1;
}
inline void write(int x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x/10) write(x/10);
    putchar(x%10+'0');
}
int he[sz],num[sz],s[sz],n;
inline void add()
{
    memset(he,0,sizeof(he));
    he[0]=max(s[0],num[0]);
    for(RI i=1;i<=he[0];++i)
    {
        he[i]+=s[i]+num[i];
        he[i+1]=he[i]/10;
        he[i]%=10;
    }
    while(he[ he[0]+1 ]>0)
    {
        he[ he[0]+2 ]=he[ he[0]+1 ]/10;
        he[ he[0]+1 ]%=10;
        he[0]++;
    }
    s[0]=he[0];
    for(RI i=1;i<=he[0];++i)
        s[i]=he[i];
}
int main()
{
    read(n);
    num[0]=1,num[1]=1;
    s[0]=1,s[0]=0;
    for(RI k=1;k<=n;++k)
    {
        memset(he,0,sizeof(he));
        he[0]=num[0];
        for(RI i=1;i<=num[0];++i)
        {
            he[i]+=num[i]*k;
            he[i+1]=he[i]/10;
            he[i]%=10;
        }
        while(he[ he[0]+1 ]>0)
        {
            he[ he[0]+2 ]=he[ he[0]+1 ]/10;
            he[ he[0]+1 ]%=10;
            he[0]++;
        }
        for(RI i=1;i<=he[0];++i)
            num[i]=he[i];
        num[0]=he[0];
        add();
    }
    for(RI i=s[0];i>=1;--i)
        write(s[i]);
    puts("");
    return 0;
}
