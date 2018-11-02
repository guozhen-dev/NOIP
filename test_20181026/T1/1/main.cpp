//
//  main.cpp
//  1
//
//  Created by 丁国真 on 2018/10/20.
//  Copyright © 2018 丁国真. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[10000000];
void swap(int *a , int *b){
    int t ;
    t = *a;
    *a = *b ;
    *b = t;
}
int main(int argc, const char * argv[]) {
    int a , b ;
    cin >> a >> b ;
    memset(dp, 0, sizeof(dp));
    dp[a]=1;
    dp[b]=1;
    dp[0]=1;
    if(a>b) swap(&a,&b);
    for(int i=a ;i <= sizeof(dp)/sizeof(dp[0]);i++){
        bool t1,t2;
        if ( i>=a && dp[i-a]) t1=1;
        else t1 = 0 ;
        if (i >= b && dp[i-b]) t2=1;
        else t2=0;
        dp[i] = t1 or t2;
    }
    for (int i= sizeof(dp)/sizeof(dp[0]);i;--i){
        if (!dp[i]) {cout << i;break;}
    }
    return 0;
}
