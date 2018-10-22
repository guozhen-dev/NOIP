//
//  main.cpp
//  P2723
//
//  Created by 丁国真 on 2018/10/21.
//  Copyright © 2018 丁国真. All rights reserved.
//
#include<bits/stdc++.h>
using namespace std;
int n,k,a[110],f[110000];
int minn;
int main()
{
    int i,j,t;
    scanf("%d%d",&k,&n);
    for(i=1;i<=k;i++) {
        cin >>a[i];
    }
    f[0]=1;
    for(i=1;i<=n;i++)
    {
        minn=INT_MAX;
        for(j=1;j<=k;j++)
        {
            for(t=0;t<i;t++)
            {
                if(a[j]*f[t]>f[i-1])
                {
                    minn=min(minn,a[j]*f[t]);
                    break;
                }
            }
        }
        f[i]=minn;
    }
    cout<<f[n];
    return 0;
}
