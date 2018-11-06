#include <bits/stdc++.h>
using namespace std;
int data[50][50];
int dp[50][50][50][50];
int m, n ;
int max_of(int a , int b ,int c ,int d ){
	int arr[5];
	arr[0] = a ;
	arr[1] = b ;
	arr[2] = c ;
	arr[3] = d ;
	sort(arr,arr+4);
	return arr[3];
}	
int main(){
	cin >> m >> n;
	for(int i = 0 ;i< m ; i++){
		for(int j = 0 ; j < n ;j++){
			cin >>data[i][j];
		}
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < m ; k++){
				for (int l = j+1 ; l <n ; l++){
					dp[i][j][k][l]=max_of(i>0&&k>0?dp[i-1][j][k-1][l]:0,i>0&&l>0?dp[i-1][j][k][l-1]:0,j>0&&k>0?dp[i][j-1][k-1][l]:0,j>0&&l>0?dp[i][j-1][k][l-1]:0) + data[i][j] + data[k][l] ;
//					cout << i <<j <<k<<l<<" " <<dp[i][j][k][l]<<endl;
				}
			}
		}
	}
	cout << max(dp[m-1][n-2][m-2][n-1],dp[m-2][n-1][m-1][n-2])<<endl ;
	return 0 ;
}
