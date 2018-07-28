#include <bits/stdc++.h>
using namespace std;
char s[21], t[21];
int ans[21][21];
int m, n;

bool match(int i, int j)
{
    if (i == m+1 && j == n+1)
        return true;
    if (i == m+1 || j == n+1)
        return false;
    int& a = ans[i][j];
    if (a != 0)
        return a;
    if (s[i] == '?')
        return a = match(i+1, j+1);
    if (s[i] == '*') {
        if (match(i, j+1))
            return a = true;
        if (match(i+1, j))
            return a = true;
        return a = match(i+1, j+1);
    }
    if (s[i] != t[j])
        return a = false;
    return a = match(i+1, j+1);
}
void init () {
	memset(ans, 0, sizeof(ans));
}
int main()
{
	freopen("1.in","r",stdin);
    init () ;
    cin>> s >> t ;
    m = strlen(s);
    n = strlen(t);
    if (match(0, 0))
        cout << "matched";
    else
        cout << "not matched" ;
    return 0;
}
