#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
return a>b;
}
int main(){
int num[6]={1,2,4,7,15,34};
sort(num,num+6); 
int pos1=lower_bound(num,num+6,7)-num; 
int pos2=upper_bound(num,num+6,7)-num;
cout<<pos1<<" "<<num[pos1]<<endl;
cout<<pos2<<" "<<num[pos2]<<endl;
sort(num,num+6,cmp); 
int pos3=lower_bound(num,num+6,7,greater<int>())-num;
int pos4=upper_bound(num,num+6,7,greater<int>())-num;
cout<<pos3<<" "<<num[pos3]<<endl;
cout<<pos4<<" "<<num[pos4]<<endl;
return 0;
}
