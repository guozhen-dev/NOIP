#include<bits/stdc++.h>
using namespace std;
int n,ans;
int num[1000010],dp[1000010];//dp[i]以i结尾的最.大.子段和
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)
	{
		if(dp[i-1]>0)
			dp[i]=dp[i-1]+num[i];//这样若dp[i]为正数,正确,若为负数,.一定不会作为答案不影响正确性
		else dp[i]=num[i];//前.面的负数必然不不能使当前值更更.大
		if(dp[i]>ans)
			ans=dp[i];
	}
	printf("%d",ans);
	return 0;
}
