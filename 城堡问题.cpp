#include <bits/stdc++.h>
using namespace std ;
int n,m  ;
int mapp[57][57];
int visited[57][57];
int flag ;
int total;
int maxaaa;
int data[57*57];
void testoutput(){
	for(int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < m ; j++){
			cout << visited[i][j]<<" ";
		}
		cout << endl ;
	}
}
void readin_and_init() {
	cin >> n >> m;
	flag = 1;
	for ( int i = 0 ; i < n ; i++){
		for ( int j =0 ; j < m ; j++){
			cin >> mapp[i][j];
			visited[i][j]=0;
		}
	}

}
bool if_avai (int x , char dir){
	// cout << "***"<<x <<" "<<dir <<"***" <<endl ;
	if (dir == 'W'){
		if(x%2) {return 0;}
		else {return 1 ;}
	}else if ( dir == 'E'){
		if ((x>>2)%2) {return 0 ;}
		else {return 1 ;}
	}else if ( dir == 'S'){
		if ((x>>3)%2) {return 0;}
		else {return 1 ;}
	}else if ( dir == 'N'){
		if ((x>>1)%2) {return 0 ;}
		else {return 1 ;}
	}else {
		cout << "if_avai_err "<<endl ;
		exit(255);
	}
}
void dfs(int x , int y){
	// cout << "------"<<x<<" "<<y<<"--------"<<endl ;
	// testoutput() ;
	// cout <<if_avai(mapp[x][y],'E');
	if (visited[x][y]!=0) return ;
	else visited[x][y] = flag;
	if (x>0 and if_avai(mapp[x][y],'N')){
		
		// visited[x-1][y] = flag ;
		dfs(x-1,y);
	}
	if (x < n-1 and if_avai(mapp[x][y],'S')){
		// visited[x+1][y] = flag ;
		// visited[x][y] = flag;
		// cout << 'S';
		dfs(x+1,y);
	}
	if (y>0 and if_avai(mapp[x][y],'W')){
		// visited[x][y-1] = flag ;
		// cout << mapp[1][1]<<endl;
		// visited[x][y] = flag;
		// cout <<"wWWWwww"<<x<<" "<<y<<endl;
		dfs(x,y-1);
	}
	if (y<m-1 and if_avai(mapp[x][y],'E')){
		// visited[x][y] = flag;
		// visited[x][y+1]=flag  ;
		// cout <<'E';
		dfs(x,y+1);
	}else {return ;}
}

int main () {
	// cout << (11>>2);
	// exit(0);
	// freopen("1.cpp","r",stdin);
	readin_and_init() ;
	for (int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < m ; j ++){
			flag++;
			dfs(i,j);
		}
	}
	// testoutput();
	for (int i = 0 ; i < n ; i ++){
		for (int j = 0 ; j < m ; j++){
			data[visited[i][j]]++;
		}
	}
	for ( int i = 0 ; i < 57*57 ; i++){
		if (data[i]!= 0) total ++;
		maxaaa = max(maxaaa,data[i]);

	}
	cout << total <<endl<<maxaaa<<endl ;
	return 0 ;
}