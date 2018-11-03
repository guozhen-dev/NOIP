#include <bits/stdc++.h>
using namespace std ;
int N ;
int input[1001][1001];
int ans[1000][1000];
void readin( ) {
	memset(input,0xff,sizeof(input));
	for (int i = 0 ; i  < N ; i++){
		for (int j = 0 ; j < i+1 ; j++){
			cin >> input[i][j];
		}
	}
	return  ;
}
int main(){
	cin >> N ;
	readin();
	memset(ans,0xff,sizeof(ans));
	if ( N == 1){
		cout << input[0][0];
		exit(0);
	}
	for (int i = N-2 ; i > 0 ; i--){
		for (int j = 0 ; j < i+1 ; j ++){
			input[i][j] = input[i][j]+max(input[i+1][j],input[i+1][j+1]);
		}
	}
	input[0][0] = input[0][0]+max(input[1][0],input[1][1]);
	cout << input[0][0];
	return 0 ;
}	
