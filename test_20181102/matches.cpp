#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int get_matches(int n){
    int i,j,sum=0;
    if(n==0)
    return 6;
    while(n){
       sum+=a[n%10];
       n/=10;
    }
    return sum;
}
int main(){
    int i,j,k,n,sum;
    cin >> n ;
    n-=4;sum=0;
    for(i=0;i<=1000;i++) {
	    for(j=0;j<=1000;j++) {
	      if(get_matches(i)+get_matches(j)+get_matches(i+j)==n) {
	            sum++;
     		 }
    	}
    }  
   cout << sum ;
   return 0;
} 

