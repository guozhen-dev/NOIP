#include<bits/stdc++.h>
using namespace std;
int n,ans;
int num[1000010],dp[1000010];//dp[i]��i��β����.��.�Ӷκ�
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)
	{
		if(dp[i-1]>0)
			dp[i]=dp[i-1]+num[i];//������dp[i]Ϊ����,��ȷ,��Ϊ����,.һ��������Ϊ�𰸲�Ӱ����ȷ��
		else dp[i]=num[i];//ǰ.��ĸ�����Ȼ������ʹ��ǰֵ����.��
		if(dp[i]>ans)
			ans=dp[i];
	}
	printf("%d",ans);
	return 0;
}
