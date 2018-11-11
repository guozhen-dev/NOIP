#include<bits/stdc++.h>
    using namespace std;
    string a,b,c;//c是用来辅助b添位的
    int ans[10010],sum;//用ans存答案
    bool pd,bo=1;//pd用来判断b>a
    int main()
    {
        cin>>a>>b;
        if(a==b)//a=b直接输出0
        {
            cout<<0;
            return 0;
        }
        else if(a.length()>b.length()) pd=1;//a的位数比b多,那就肯定比b大
        else if(a.length()<b.length()) pd=0;//反之,也是一样的
        else if(a.length()==b.length())//a的位数和b一样
        {
            if(a>b) pd=1;//可以直接字典序比较
            else pd=0;
        }
        if(!pd) swap(a,b);//b>a,调换一下就是了
        sum=a.length()-b.length();//sum存a b位数差
        for(int i=0;i<sum;i++) c=c+"0";//c存了需要添的0
        b=c+b;//给b加上
        for(int i=a.length()-1;i>=0;i--)//个位对齐,是从a还是b开始不重要
        {
            if(a[i]>=b[i]) ans[i]=a[i]-b[i];//一位一位进行计算
            else
            {
                a[i-1]--;//不够借位
                ans[i]=a[i]+10-b[i];
            }
        }
        if(!pd) cout<<'-';//别忘了输出负号
        for(int i=0;i<=b.length()-1;i++)
        {    
            if(bo && ans[i]==0) continue;//结果最高位上可能为0，直接跳过
            else if(ans[i]>0) bo=0;//找到了不为0的最高位
             cout<<ans[i];
        }
        //system("pause");
        return 0;
}
