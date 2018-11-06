#include <bits/stdc++.h>
using namespace std;
int N;
int data[107];
int dp1[107];
int dp2[107];
int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		cin >> data[i];
	}
	dp1[0]=dp2[0]=1;
	for(int i = 1 ; i<= N ; i++){
		int max_result=1;
		for(int j = 1 ; j < i ; j++ ){
			if(data[i]>data[j]) max_result = max(max_result,dp1[j]+1);
		}
		dp1[i]=max_result;
	}
	for(int i = N ; i > 0 ; i--){
		int max_result=1;
		for (int j = N ; j>i; j--){
			if(data[j]<data[i]) max_result = max(max_result,dp2[j]+1);
		}
		dp2[i]=max_result;
	}
	int max_ans;
	for (int i = 1 ; i<=N ;i++){
		max_ans = max(max_ans,dp1[i]+dp2[i]-1);
	}
	cout<< N-max_ans;
	return 0 ;
}

