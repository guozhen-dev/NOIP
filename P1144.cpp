#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
const int mode = 100003;
bool in[maxn] = {};
int n, m, dis[maxn], cnt[maxn] = {};
vector<int> G[maxn];

void spfa()
{
    dis[1] = 0;
    queue<int> que;
    que.push(1);
    in[1] = true;
    cnt[1] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        in[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1; 
                cnt[v] = cnt[u];
                if (!in[v]) {
                    que.push(v);
                    in[v] = true;
                }
            } else if (dis[u] + 1 == dis[v]) {
                cnt[v] += cnt[u];
                cnt[v] %= mode;
                if (!in[v]) {
                    que.push(v);
                    in[v] = true;
                }
            }
        }
    }
}

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    spfa();
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }
}

