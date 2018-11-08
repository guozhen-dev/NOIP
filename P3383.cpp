#include<bits/stdc++.h>
using namespace std;
int prime[10000007];
int Ma , N;
int x ;
int main(){
	scanf("%d%d",&N,&Ma);
	for(register int i = 0  ;i <= N ; i++ ){
		prime[i]=1;
	}
	prime[0] = prime[1] = 0;
	for(register int i = 2 ; i < N+5 ; i++){
		if(!prime[i]) continue;
		for(register int j = 2 ; j*i <= N ; j++){
			prime[i*j] = 0;
		}
	}
	for (register int i = 0 ; i < Ma ; i++){
		scanf("%d",&x);
		if ( prime[x] )  puts("Yes");
		else puts("No");
	}
	return 0;
}	
