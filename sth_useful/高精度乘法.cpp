#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[205],b[205];
	int aa[205]={0},bb[205]={0},c[205]={0};
	
	gets(a);
	int la=strlen(a);
	gets(b);
	int lb=strlen(b);
	
	for(int i=0;i<la;i++)
	{
		aa[la-i]=a[i]-'0';
	}
	for(int i=0;i<lb;i++)
	{
		bb[lb-i]=b[i]-'0';
	}
	
	int x;
	for(int i=1;i<=la;i++)
	{
	    x=0;//仅在同一位上有进位 
		for(int j=1;j<=lb;j++)
		{
	           c[i+j-1]=c[i+j-1]+aa[i]*bb[j]+x;
		    x=c[i+j-1]/10;
		    c[i+j-1]%=10;
		}
		c[i+lb]=x;//进位，i的大小决定竖式中空几格 
	}
	int lc=la+lb;//？ 
	
	while (c[lc]==0&&lc>1) lc--;//表示最高位的0，即去前导 
	
	for(int i=lc;i>=1;i--)
	{
		printf("%d",c[i]);
	}
	
	return 0;
}
