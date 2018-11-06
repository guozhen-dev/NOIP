#include <bits/stdc++.h>
using namespace std;
int data[41];
__int128 dp[41][7];
int N,K;
void give_ans(__int128);

__int128 get_num(int x , int y ){
	__int128 ret=0;
	if (x==y) return (__int128)data[x];
	for (int i = x ; i <= y; i++){
		ret *= 10 ;
		ret += data[i];
	}
	return ret;
}

__int128 get_max(int x , int y ){
	if (!y) return get_num(0,x);
	__int128 ret=0 ;
	for (int t = y ; t <= x ; t++){
		ret = max(ret,dp[t-1][y-1]*get_num(t,x));
	}
	return ret;	
}

void give_ans(__int128 x){
	if ( x==0 ) cout << 0 ;
	stack<int> ans;
	while (x){
		ans.push((int)(x%10));
		x/=10;
	}
	while (ans.size()){
		cout << ans.top() ;
		ans.pop();
	}
}

void output(){
	for(int i = 0 ; i < N ; i++){
		for (int j = 0 ; j <= K ; j++){
			give_ans(dp[i][j]);
			cout <<" ";
		}
		cout <<endl;
	}
	cout <<"-------------------------"<<endl;
	return ;
	cout << endl ;
}

int main(){
	string input;
	cin >> N >> K;
	cin>>input;
	for (int i = 0 ; i < N ; i++){
		data[i]=input[i]-'0';
	}
	for (int i = 0 ; i < N ; i++ ){
		for (int j = 0 ; j <= K ;j++) {
			dp[i][j] = get_max(i,j);
		}
	}
	give_ans(dp[N-1][K]);
	return 0 ;
}

