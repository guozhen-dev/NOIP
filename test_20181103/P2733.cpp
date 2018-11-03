#include <bits/stdc++.h>
using namespace std;
int ori[257];
int x ;
int dp[257][257][257];
bool data[257][257];
int ans[257];
struct node{
	        int line_num;
	        int row_num;
};
struct node check[257][257];
bool line_ok(int i , int j , int k){
        if ( check[i-k+1][j].line_num + k-1 == check[i][j].line_num and data[i-k+1][j] > 0) {
//		cout <<"line";
//		cout << check[i-k+1][j].line_num<<" "<<check[i][j].line_num<<" "<<i<<" "<<j<<" "<<k <<endl;
		return 1 ;
	}
	else return 0 ;

}
bool row_ok( int i , int j , int k ){
	if ( check[i][j-k+1].row_num + k-1 == check[i][j].row_num and data[i][j-k+1]>0) {
//		cout <<"row";
//		cout << check[i][j-k+1].row_num<<" "<<check[i][j].row_num<<" "<<i<<" "<<j<<" "<<k <<endl ;
		return 1 ;
	}
	else return 0 ;
}

void mian(){
	memset(ori,0x00,sizeof(ori));
	memset(data,0x00,sizeof(data));
	memset(dp,0x00,sizeof(dp));
	memset(ans,0x00,sizeof(ans));
	memset(check,0x00,sizeof(check));
	return ;
}
int main (){
	mian() ;
	cin >> x ;
	//getchar() ;
	for (int i = 0 ; i < x ; i++){
		string input ;
		cin >> input;
		int j = 0 ;
		while(1){
			switch (input[j]){
				case '1':
					data[i][j] = 1 ;
					j++;
					break;
				case '0':
					data[i][j] = 0 ;
					j++;
					break;
				case '\0':
					goto line_finish ;
					break;
				default :
					break;
			}
		}
		line_finish: continue;
	}
	for (int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
			if (!data[i][j]){
			       check[i][j].row_num = check[i][j-1].row_num;
			       check[i][j].line_num = check[i-1][j].line_num;
			}else if (data[i][j]){
				check[i][j].row_num = check[i][j-1].row_num+1;
				check[i][j].line_num = check[i-1][j].line_num+1;
			}
		}
	}
	//test row line 
/*	
	for (int i = 0 ; i < x ; i++){
		for (int j = 0; j < x ; j++){
			cout << data[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0 ; i < x ; i++ ){
		for (int j = 0 ; j < x ; j++){
			cout << check[i][j].line_num<<" ";
		}
		cout << endl ;
	}
	//exit(0);
*/
	for(int i = 0 ; i < x ; i++){
		for (int j = 0 ; j < x ; j++ ) {
			for (int k = 1 ; k <= x ; k++){
				if ((i-(k-1)<0 or j-(k-1)<0) ){
					dp[i][j][k] = 0;
				}else if(k==1 and data[i][j]==1){
					dp[i][j][k] = 1;
				}else if(k==1 and data[i][j]==0){
					dp[i][j][k] = 0 ;
				}
				else{
					dp[i][j][k]=dp[i-1][j-1][k-1] && line_ok(i,j,k) && row_ok(i,j,k) && data[i][j];
					if ( dp[i][j][k]) ans[k]++;
				}
			}
		}
	}
/*	for (int i = 0 ; i < x ; i++ ) {
		for (int j = 0 ; j < x ; j++){
			cout << "("<<i<<","<<j<<")"<<" ";
			for(int k = 1 ; k <= x ; k++){
				cout << dp[i][j][k]<<" ";
			}
			cout << endl ;
		}
	}
*/
	for (int i = 2 ; i <=x ; i++){
		if(ans[i])  cout << i << " "<<ans[i] << endl;
	}
	return 0 ;	
}
