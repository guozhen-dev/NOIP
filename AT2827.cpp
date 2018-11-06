#include<bits/stdc++.h>
using namespace std;
int data[100007];
int min_val[100007];
int N ;
int max_len ;
int main(){
	cin >> N;
	for(int i = 1 ; i<=N ;i++){
		cin >> data[i];
	}
	max_len = 1;
	min_val[1]=data[1];
	for (int i = 2 ; i<= N ; i++){
		if(data[i]>min_val[max_len]) min_val[++max_len]=data[i];
		else min_val[lower_bound(min_val+1,min_val+max_len+1,data[i])-min_val] = data[i];
		for (int j = 0 ; j<max_len; j++){
			cout << min_val[j]<< " ";
		}
		cout <<endl;
	}

	cout <<max_len<<endl ;
	return 0 ;
}
	

