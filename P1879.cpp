#include <bits/stdc++.h>
using namespace std;
const int M = 1e9;
int m, n, f[13][4096], F[13], lxt[13][13];
bool __ans[4096];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> lxt[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            F[i] = (F[i] << 1) + lxt[i][j];
    int MAX_OF_ANS_LINE = 1 << n;
    for (int i = 0; i < MAX_OF_ANS_LINE; i++)
        __ans[i] = ((i&(i<<1))==0) && ((i&(i>>1))==0);
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < MAX_OF_ANS_LINE; j++)
            if (__ans[j] && ((j & F[i]) == j))
                for (int k = 0; k < MAX_OF_ANS_LINE; k++)
                    if ((k & j) == 0)
                        f[i][j] = (f[i][j] + f[i-1][k]) % M;
    int ans = 0;
    for (int i = 0; i < MAX_OF_ANS_LINE; i++){
			ans += f[m][i]
			ans %= M;
		}
    cout << ans << endl;
    return 0;
}
