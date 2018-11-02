//
//  main.cpp
//  3
//
//  Created by 丁国真 on 2018/10/20.
//  Copyright © 2018 丁国真. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxn=70;
int n,b,d,ans[maxn],len;
int main(int argc, const char * argv[]) {
    cin>>n>>b>>d;
    len++;
    ans[len]=0;
    int i=1;
    while(len<n){
        bool flag=false;
        for(int j=len;j>=1;j--)
            if(__builtin_popcount(ans[j]^i)<d){
                flag=true;
                break;
            }
        if(!flag){
            len++;
            ans[len]=i;
        }
        i++;
    }
    for(i=1;i<=len;i++){
        cout << ans[i];
        if(i%10==0)cout<<endl;
    }
    return 0;
}
