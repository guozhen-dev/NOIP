#include <bits/stdc++.h>
using namespace std;
struct node{
	int x ;
	int y ;
	int z ;
};
int N ;
struct node data[50007];
bool cmp(struct node a , struct node b){
	return a.z<b.z;
}
double get_dis(struct node a ,struct node b){
	double ret;
	ret = sqrt(pow(abs(b.x-a.x),2)+pow(abs(a.y-b.y),2)+pow(abs(a.z-b.z),2));
	return ret ;
}
double ans;
int main (){
	cin >> N ;
	ans = 0 ;
	for (int i = 0 ; i < N ; i++ ){
		cin >> data[i].x>>data[i].y>>data[i].z;
	}
	sort(data,data+N,cmp);
//	for (int i = 0 ; i < N ; i++ ){
//		cout << data[i].x<<" "<<data[i].y<<" "<<data[i].z<<endl;
//	}
	for(int i = 1 ; i < N ; i++){
		ans += get_dis(data[i-1],data[i]);
	}
	printf("%.3f",ans);
	return 0 ;
}
