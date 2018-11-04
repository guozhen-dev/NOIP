#include<bits/stdc++.h>
using namespace std;
int B[101][101][11],S[101][101][11];
int n,m; 
int a[101];
int mod(int a)
{
    return ((a%10)+10)%10;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for (int i=1;i<=2*n;i++)
      a[i]+=a[i-1];
    for (int l=1;l<=2*n;l++)
      for (int r=l;r<=2*n;r++)
        B[l][r][1]=S[l][r][1]=mod(a[r]-a[l-1]);
    for (int i=2;i<=m;i++)
      for (int l=1;l<=2*n;l++)
        for (int r=l+i-1;r<=2*n;r++)
          S[l][r][i]=INT_MAX;
    for (int i=2;i<=m;i++)
      for (int l=1;l<=2*n;l++)
        for (int r=l+i-1;r<=2*n;r++)
        {
            for (int k=l+i-2;k<r;k++)
            {
                S[l][r][i]=min (S[l][r][i],S[l][k][i-1]*mod(a[r]-a[k]));
                B[l][r][i]=max (B[l][r][i],B[l][k][i-1]*mod(a[r]-a[k]));
          }
        }
    int Max=0,Min=INT_MAX;
    for (int i=1;i<=n;i++)
    {
        Max=max(Max,B[i][i+n-1][m]);
        Min=min(Min,S[i][i+n-1][m]);
    }
    cout << Min << endl <<Max;
		return 0;
}
