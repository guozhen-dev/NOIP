#include<bits/stdc++.h>
using namespace std;
int f[5000][5000];
char a[10000],b[10000];
int main()
{
	while(~scanf("%s%s",a+1,b+1))
	{
		int len1=strlen(a+1);
		int len2=strlen(b+1);
		f[0][0]=0;//a串串匹配到第i位,b串串第j位的最.长公共.子序列列.长度
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				if(a[i]==b[j])//注意不不要写成a[i]==b[i]
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
			printf("%d\n",f[len1][len2]);
		}
	return 0;
}
