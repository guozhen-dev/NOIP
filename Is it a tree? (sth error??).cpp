#include <bits/stdc++.h>
using namespace std ;
int outptr[100000];
int inptr[100000];
bool used[100000];
int index123 ;
struct readindata
{
	int x ; int y ;
};
struct readindata a[10000];
readindata to_data(int x , int y ){
	struct readindata aa;
	aa.x = x ;
	aa.y = y ;
	return aa ;
}
int round1 ;
void reset () {
	round1 ++ ;
	index123 = 0;
	memset(a,0,sizeof(a));
	for ( int i = 0  ; i < 100000; i++){
		outptr[i]=inptr[i]=used[i]=0;
	}
}
void output(){
	int out ;
	int in = 0  ;
	int fail = 0 ;
	for ( int i = 0 ; i < 100000; i++){
		if (inptr[i] > 1 )  fail = 1;
		if (inptr[i] == 0 and used[i])  in++ ;
	}
	if (in != 1 ) fail = 1 ;
	if (!fail){
		cout << "Case" <<" "<< round1 <<" " <<"is a tree."<<endl;
	}else {
		cout << "Case" <<" "<<round1 <<" "<<"is not a tree."<<endl;
	}
}
int main() {
	freopen("1.in","r",stdin);
	round1 = 1 ;
	while(1){
		int x , y ;
		cin >> x >> y ;
		if (x == 0 and y == 0 ){
			output () ;
			reset() ;
		}
		if ( x == -1 and y == -1 ){
			return 0 ;
			exit(0);
		}
		a[index123++] = to_data(x,y);
		for(int p = 0 ; p < index123-1 ; p++){
			if (a[p].x==a[index123-1].x and a[p].y == a[index123-1].y){
				outptr[x]--;
				inptr[y]--;
			}
		}
		outptr[x]++;
		inptr[y]++;
		used[x]=used[y] = 1 ;
		
	}
	
}