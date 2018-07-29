#include <bits/stdc++.h>
using namespace std ;
const int MAX_LEN = 15;
int min_covered_area[1<<MAX_LEN];
int used;
int node[15][2];
int num;
int covered_area(int i,int j)
{
    if(node[i][0]==node[j][0]) return abs(node[i][1]-node[j][1]);
    if(node[i][1]==node[j][1]) return abs(node[i][0]-node[j][0]);
    return abs(node[i][1]-node[j][1])*abs(node[i][0]-node[j][0]);
}
int findnxt(int n)
{
    int i,j,k;
    if(min_covered_area[n]>=0)
        return min_covered_area[n];
    if(n==0)
        return min_covered_area[n]=0;
    min_covered_area[n]=INT_MAX;
    for(i=0;i<num;i++)
    {
        if(n&(1<<i))
        {
            for(j=0;j<num;j++)
            {
                if(i!=j)
                {
                    int tmp,s;
                    tmp=n&(~((1<<i)|(1<<j)));
                    for(k=0;k<num;k++)
                        if((node[i][0]==node[k][0]&&node[j][1]==node[k][1])or(node[i][1]==node[k][1]&&node[j][0]==node[k][0]))
                            tmp&=(~(1<<k));
                    s=covered_area(i,j)+findnxt(tmp);
                    if(s<min_covered_area[n])
                        min_covered_area[n]=s;
                }
            }
        }
    }
    return min_covered_area[n];
}
int main()
{
	freopen("1.in","r",stdin);
    int i;
    cin >> num ;
    while(num)
    {
        for(i=0;i<num;i++)
            cin>>node[i][0]>>node[i][1];
        memset(min_covered_area,-1,sizeof(min_covered_area));
        used=(1<<num)-1;
        cout << findnxt(used)<<endl ;
        cin >> num;
    }
    return 0;
}
