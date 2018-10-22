//
//  main.cpp
//  P2335
//
//  Created by 丁国真 on 2018/10/22.
//  Copyright © 2018 丁国真. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int data[150][150];
int ans[150][150];
int x ,y ;
inline int get_dis(int x1,int y1,int x2,int y2){
    return (abs(x1-x2)+abs(y1-y2));
}
inline int min(int a, int b)
{
    return (a>b) ? b : a;
}
inline void check(int curx, int cury ){
    if(data[curx][cury]==1) {
        ans[curx][cury] = 0 ;
        return;
    }
    for (register int i = 0 ; i < x ;i++){
        for(register int j = 0 ; j < y ; j++){
            if(data[i][j]) ans[curx][cury]=min(get_dis(curx, cury, i, j),ans[curx][cury]);
            
        }
    }
}


int main(int argc, const char * argv[]) {

    cin >> x >> y ;
    memset(ans,0x7f,sizeof(ans));
    for (int i =0 ; i < x ; i++){
        for(int j = 0 ; j < y ;j++){
            cin >> data[i][j];
        }
    }
    for (int i =0 ; i < x ; i++){
        for(int j = 0 ; j < y ;j++){
            check(i,j);
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
