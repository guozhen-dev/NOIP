//
//  main.cpp
//  2
//
//  Created by 丁国真 on 2018/10/20.
//  Copyright © 2018 丁国真. All rights reserved.
//

#include <bits/stdc++.h>
#define LL unsigned long long
#define MAXLIM 256*256-2*256+1
using namespace std;
int main(int argc, const char * argv[]) {
int f[MAXLIM + 1];
int i, j, n;
int a[11];
cin >> n;
for (i = 1; i <= n; i++)
    cin >> a[i];
f[0]=1;
for (i=1;i<=n;i++)
    for (j = a[i]; j <= MAXLIM; j++)
        f[j] = f[j] || f[j - a[i]];
int ans = 0;
for (i = MAXLIM; i >= 0; i--)
    if (f[i] == 0){
        ans = i;
        break;
    }
if (ans>MAXLIM){
    puts("0");
    exit(0);
}
cout << ans << endl;

return 0;
}
    
