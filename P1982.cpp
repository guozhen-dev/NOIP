#include<bits/stdc++.h>
using namespace std;
long long input_seq[1000007];
long long max_sub_sum[1000007];
long long score[1000007];
long long input_length , mod;
int  main(){
	cin >> input_length >> mod;
	for (long long i = 1; i <= input_length ;i++){
		cin >> input_seq[i];
		max_sub_sum[i]=input_seq[i];
	}
	long long max_sum = INT_MIN;
	for (long long i = 2 ; i <= input_length;i++){
		if ( max_sub_sum[i-1] <=0 ){
		} else {
			max_sub_sum[i]+=max_sub_sum[i-1];
		}
//		max_sum=max(max_sub_sum[i],max_sum);
//		max_sub_sum[i]=max_sum;
	}
		for (long long i = 1 ; i <= input_length ; i++){
		if (max_sum > max_sub_sum[i])
			max_sub_sum[i] = max_sum;
		else {
			max_sum = max_sub_sum[i];
		}
	}
	max_sum=INT_MIN;
	score[1]=max_sum=max_sub_sum[1];
	for(long long i = 1;i<=input_length;i++){
		score[i]=max(max_sum,score[i-1]+max_sub_sum[i-1]);
	}

	for(long long i = 1 ; i <= input_length ;i++){
	//	cout << score[i]<<" ";
		max_sum=max(max_sum,score[i]);
	}
	cout << max_sum % mod<<endl;
	return 0;	
}
