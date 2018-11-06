#include <bits/stdc++.h>
using namespace std;
int n ,m ;
__int128 dp[100][100];
void output(){
	for(int i = 0 ; i < m; i++){
		for(int j = 0 ; j < m ; j++){
//			cout << dp[i][j]<<" ";
		}
		cout << endl ;
	}
	cout <<"-------------------------------------------------"<<endl;
	return ;
}
stack<int> outputing;
__int128 ans;
void giveans(__int128 a ){
	if (a==0) puts("0");
	while(a){
		int x = a%10;
		outputing.push(x);
		a/=10;
	}
	while(outputing.size()){
		cout << outputing.top();
		outputing.pop();
	}
}
int main (){
	cin >> n >> m ;
	for (int i = 0 ; i < n ; i++){
		long long data[100]={0,};
		for (int j = 0 ; j < m ; j++){
			cin >> data[j];
		}
		memset(dp,0x00,sizeof(dp));
		for(int di = m-1 ;di>=0 ; di--){
			for(int dj = di ; dj < m ; dj++){
				if(di==dj) dp[di][dj]=data[di] *(__int128)pow(2,m);
				dp[di][dj] = max(dp[di+1][dj] + data[di]*(__int128)pow(2,m-dj+di), dp[di][dj-1]+data[dj]*(__int128)pow(2,m-dj+di));
				//output();
			}
		}
	 ans+=dp[0][m-1];
	}
	giveans(ans);
	return 0 ;
}
