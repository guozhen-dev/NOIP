#include<bits/stdc++.h>
using namespace std;
int input[100007];
int LNDS[100007];
int LIS[100007];
int min_val[100007];
int max_val[100007];
int max_len;
struct cmp{
    bool operator ()(int x ,int y){
        return x>y;
    }
};
int main(){
    int f,length=1;
    while(scanf("%d",&f)!=EOF){
        input[length++]=f;
    }
    for(int i = 0 ; i < length;i++){
        LIS[i]=LNDS[i]=1;
    }
    int ans_lis=0;
    int ans_lnds=0;
//    for(int i = 1 ; i < length;i++){
//        for(int j = 1 ; j < i; j++){
//            if(input[j] >= input[i]) LNDS[i]=max(LNDS[i],LNDS[j]+1);
//            if(input[j] < input[i])  LIS[i] =max(LIS[i],LIS[j]+1);
//        }
//        ans_lis=max(ans_lis,LIS[i]);
//        ans_lnds=max(ans_lnds,LNDS[i]);
//    }
    max_len=1;
    max_val[1]=input[1];
    for(int i = 2 ; i < length ; i++){
        if (input[i] <= max_val[max_len]) max_val[++max_len]=input[i];
        else {
            max_val[upper_bound(max_val+1, max_val+max_len+1, input[i],cmp())-max_val]= input[i];
        }
    }
    ans_lnds=max_len;
    max_len=1;
    min_val[1]=input[1];
    for(int i = 2 ; i<length;i++){
        if(input[i] > min_val[max_len]) min_val[++max_len]=input[i];
        else min_val[lower_bound(min_val+1, min_val+max_len+1, input[i])-min_val] = input[i];
    }
    
    cout << ans_lnds<<"\n"<<max_len<<endl;
    return 0;
}

