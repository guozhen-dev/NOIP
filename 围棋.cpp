#include <bits/stdc++.h>
using namespace std ;
int mapp[107][107];
int size;
int empty ;
int black;
int white;

void readin() {
	cin >> size;
	for ( int i = 0 ; i < size ; i++){
		for (int j = 0 ; j < size ; j++){
			char t ;
			cin >> t ;
			if (t == '.'){
				mapp[i][j]=0;
				empty++ ;
			} else if (t == 'B'){
				mapp[i][j] = 1;
			}else if (t == 'W'){
				mapp[i][j] = 2 ;
			}else {
				cout << "readin error"<<endl;
				exit (255);
			}
		}
	}
	return  ;
}

void init () {
	empty = black = white = 0 ;
	return ;
}
void testout () {
	for ( int i =0 ; i < size ; i++)
		{for ( int j =0 ; j < size ; j++){
					cout << mapp[i][j]<<" ";
				}
				cout << endl;}
}
void dfs(int i , int j ){
	if (mapp[i][j] == 0 ){
		return ;
	}else if (mapp[i][j] == 1){
		if(i >= 1 and mapp[i-1][j]==0){
			mapp[i-1][j]=1;
			empty--;
			dfs(i-1,j);
		}
		if(i < size-1 and mapp[i+1][j]==0){
			mapp[i+1][j] = 1 ;
			empty -- ;
			dfs(i+1,j);
		}
		if ( j >=1 and mapp[i][j-1] == 0 ){
			mapp[i][j-1] = 1 ;
			empty -- ;
			dfs(i,j-1);
		}
		if(j < size-1 and mapp[i][j+1]==0){
			mapp[i][j+1] = 1 ;
			empty -- ;
			dfs(i,j+1);
		}
	}else if (mapp[i][j] == 2){
		if(i >= 1 and mapp[i-1][j]==0){
			mapp[i-1][j]=2;
			empty--;
			dfs(i-1,j);
		}
		if(i < size-1 and mapp[i+1][j]==0){
			mapp[i+1][j] = 2 ;
			empty -- ;
			dfs(i+1,j);
		}
		if ( j >=1 and mapp[i][j-1] == 0 ){
			mapp[i][j-1] = 2 ;
			empty -- ;
			dfs(i,j-1);
		}
		if(j < size-1 and mapp[i][j+1]==0){
			mapp[i][j+1] = 2 ;
			empty -- ;
			dfs(i,j+1);
		}
	}

}
int main (){
	freopen ("1.cpp","r",stdin);
	init() ;
	readin();
	for ( int i = 0 ; i < size ; i++){
		for (int j = 0; j < size; j++)
		{
			dfs(i,j);
		}
	}
	// cout << empty <<endl;
	for  ( int i = 0 ; i < size ; i++){
		for ( int j = 0 ; j < size ; j++){
			if (mapp[i][j]==1){
				black ++;
			}else if ( mapp[i][j]==2){
				white ++;
			}else {
				cout << "total error"<<endl;
				exit(255);
			}
		}
	}
	// testout();
	cout<<black<<" "<<white<<endl;




	return 0 ;

 }