//
//  main.cpp
//  P1645
//
//  Created by 丁国真 on 2018/10/25.
//  Copyright © 2018 丁国真. All rights reserved.
//
/*
 
 1  5   10  50  100 500 1000
 I  V   X   L   C   D   M
 
 */
#include <bits/stdc++.h>
using namespace std;
int N ;
int ans[256];
char* board[4][10] = {
    {
        "","I","II","III","IV","V","VI","VII","VIII","IX"
    },
    {
        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"
    },
    {
        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"
    },
    {
        "","M","MM","MMM"
    }
};

string Re(int N){
    string re;
    re += board[3][N/1000 % 10];
    re += board[2][N/100 % 10];
    re += board[1][N/10 % 10];
    re += board[0][N % 10];
    return re;
}

int main(int argc, const char * argv[]) {
    cin >> N ;
    for (int i = 1 ; i <= N ; i++){
        string test=Re(i);
        for (int i = 0 ; i < test.length(); i++){
            ans[test[i]]++;
        }
    }
    if(ans['I']) cout << 'I' << " " << ans['I']<<endl;
    if(ans['V']) cout << 'V' << " " << ans['V']<<endl;
    if(ans['X']) cout << 'X' << " " << ans['X']<<endl;
    if(ans['L']) cout << 'L' << " " << ans['L']<<endl;
    if(ans['C']) cout << 'C' << " " << ans['C']<<endl;
    if(ans['D']) cout << 'D' << " " << ans['D']<<endl;
    if(ans['M']) cout << 'M' << " " << ans['M']<<endl;
}
//弱智打表，没有任何难度，骗子。。。




