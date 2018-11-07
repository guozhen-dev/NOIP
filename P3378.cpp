#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	register int N ;
	cin >> N ;
	while(N--){
		int oper ;
		cin >> oper;
		switch (oper) {
			case 1:
				int x ;
				cin >> x ;
				pq.push(x);
				break;
			case 2:
				cout << pq.top()<<endl;
				break;
			case 3:
				pq.pop();
				break;
		}
	}
	return 0 ;
}

