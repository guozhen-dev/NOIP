//
//  main.cpp
//  0
//
//  Created by 丁国真 on 2018/10/20.
//  Copyright © 2018 丁国真. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
int flag,f,g,h,x,y,p,z;
char a[100][100],
b[100][100],
c[100][100],
d[100][100],
e[100][100],
w[100][100],
r[100][100],
t[100][100];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=a[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]=b[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]!=d[i][j])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        puts("1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            e[i][j]=a[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            w[i][j]=e[n+1-i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(w[i][j]!=d[i][j])
            {
                f=1;
                break;
            }
        }
    }
    if(f==0&&flag==1){
        puts("3");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            r[i][j]=a[n+1-i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=r[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=d[i][j])
            {
                g=1;
                break;
            }
        }
    }
    if(g==0&&f==1&&flag==1){
        puts("2");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=a[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=d[i][j])
            {
                x=1;
                break;
            }
        }
    }
    if(x==0&&g==1&&f==1&&flag==1){
        puts("4");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=a[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=t[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]=b[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]!=d[i][j]){
                y=1;
                break;
            }
        }
    }
    if(y==0&&x==1&&g==1&&f==1&&flag==1){
        puts("5");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=a[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=t[n+1-i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]=b[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]!=d[i][j]){
                z=1;
                break;
            }
        }
    }
    if(z==0&&y==1&&x==1&&g==1&&f==1&&flag==1){
        puts("5");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=a[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=t[n+1-i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]=b[i][n+1-j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]!=d[i][j]){
                p=1;
                break;
            }
        }
    }
    if(p==0&&z==1&&y==1&&x==1&&g==1&&f==1&&flag==1){
        puts("5");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=d[i][j]){
                h=1;
                break;
            }
        }
    }
    if(h==0&&x==1&&y==1&&z==1&&p==1&&g==1&&f==1&&flag==1){
        puts("6");
        return 0;
    }
    if(h==1&&x==1&&y==1&&z==1&&p==1&&g==1&&f==1&&flag==1)
        puts("7");
    return 0;
}
