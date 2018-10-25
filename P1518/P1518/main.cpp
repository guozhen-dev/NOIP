//
//  main.cpp
//  P1518
//
//  Created by 丁国真 on 2018/10/25.
//  Copyright © 2018 丁国真. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
char input[12][12];
char dirf,dirc;
struct node{
    int x ; int y ;
};
struct node F,C,Fori,Cori;

void readln(){
    for (int i = 1 ; i < 11 ; i++){
        for ( int j = 1 ; j < 11 ; j++){
            cin >> input[i][j];
            switch (input[i][j]) {
                case 'F':
                    F.x=i;
                    F.y=j;
                    input[i][j]='.';
                    break;
                case 'C':
                    C.x=i;
                    C.y=j;
                    input[i][j]='.';
                default:
                    break;
            }
        }
    }
}
void setsides(){
    for (int i = 0 ; i < 12 ;i++){
        input[0][i]='*';
        input[i][0]='*';
        input[11][i]='*';
        input[i][11]='*';
    }
}

void checkmap(){
    for (int i = 0 ; i < 12 ; i ++){
        for (int j = 0 ; j < 12 ; j++){
            if (F.x==i and F.y ==j )cout << "F ";
            else if (C.x==i and C.y ==j )cout << "C ";
            else cout << input[i][j]<<' ';
        }
        cout << endl;
    }
}
int check(){
    if (F.x==C.x and F.y==C.y) return 1;
    else if (F.x==Fori.x and F.y==Fori.y and C.y==Cori.y and C.x==Cori.x) return 2;
    return 0;
}
void turning(char a){
    switch (a) {
        case 'F':
            if(dirf=='N') dirf='E';
            else if(dirf=='E') dirf='S';
            else if(dirf=='S') dirf='W';
            else if(dirf=='W') dirf='N';
            break;
        case 'C':
            if(dirc=='N') dirc='E';
            else if(dirc=='E') dirc='S';
            else if(dirc=='S') dirc='W';
            else if(dirc=='W') dirc='N';
        default:
            break;
    }
}
void walking(){
    switch (dirf) {
        case 'W':
            if(input[F.x][F.y-1]=='*') turning('F');
            else F.y-=1;
            break;
        case 'S':
            if(input[F.x+1][F.y]=='*') turning('F');
            else F.x += 1;
            break;
        case 'E':
            if(input[F.x][F.y+1]=='*') turning('F');
            else F.y += 1;
            break;
        case 'N':
            if(input[F.x-1][F.y]=='*') turning('F');
            else F.x -= 1;
            break;
        default:
            break;
    }
    switch (dirc) {
        case 'W':
            if(input[C.x][C.y-1]=='*') turning('C');
            else C.y-=1;
            break;
        case 'S':
            if(input[C.x+1][C.y]=='*') turning('C');
            else C.x += 1;
            break;
        case 'E':
            if(input[C.x][C.y+1]=='*') turning('C');
            else C.y += 1;
            break;
        case 'N':
            if(input[C.x-1][C.y]=='*') turning('C');
            else C.x -= 1;
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    readln();
    setsides();
    Fori=F;
    Cori=C;
//    checkmap();
    int cnt= 0 ;
    dirf='N';
    dirc='N';
    while(true){
//        checkmap();
//        cout << endl;
        if (cnt > 1e8) {
            cout << 0;
            exit(0);
        }
        cnt++;
        walking();
        switch (check()) {
            case 1:
                cout << cnt ;
                exit(0);
                break;
            case 2:
                cout << 0;
                exit(0);
            default:
                break;
        }
        
    }
    return 0;
}
