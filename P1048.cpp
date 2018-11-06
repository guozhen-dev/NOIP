#include <bits/stdc++.h>
using namespace std;
int dp[1007][107];
int T,M;
struct med{
	int weight;
	int value;
};
bool cmp (struct med a ,struct med b ) {
	if (a.weight<b.weight) return 1;
	else return 0 ;
}
struct med data[107];
void output() {
	for(int i = 0 ; i < T ; i++){
		for (int j = 0 ; j < M ; j++){
			cout <<dp[i][j]<<" ";
		}
		cout <<endl ;
	}
	cout <<"------------------------"<<endl ;
	return;
}

int main(){
	cin >> T>>M;
	for (int i = 1 ; i <= M ;i++){
		cin >> data[i].weight>>data[i].value;
	}
	sort(data,data+M,cmp);
	for (int i = 1 ; i <= T ; i++ ) {
		for (int j = 1 ; j <= M ; j++) {
			if (i < data[j].weight) dp[i][j] = dp[i][j-1];
			else dp[i][j] = max(dp[i-data[j].weight][j-1]+data[j].value,dp[i][j-1]);
//			output() ;
		}
	}
	cout << dp[T][M];
	return 0 ;
}


