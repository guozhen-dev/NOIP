#include<bits/stdc++.h>
    using namespace std;
    string a,b,c;//c����������b��λ��
    int ans[10010],sum;//��ans���
    bool pd,bo=1;//pd�����ж�b>a
    int main()
    {
        cin>>a>>b;
        if(a==b)//a=bֱ�����0
        {
            cout<<0;
            return 0;
        }
        else if(a.length()>b.length()) pd=1;//a��λ����b��,�ǾͿ϶���b��
        else if(a.length()<b.length()) pd=0;//��֮,Ҳ��һ����
        else if(a.length()==b.length())//a��λ����bһ��
        {
            if(a>b) pd=1;//����ֱ���ֵ���Ƚ�
            else pd=0;
        }
        if(!pd) swap(a,b);//b>a,����һ�¾�����
        sum=a.length()-b.length();//sum��a bλ����
        for(int i=0;i<sum;i++) c=c+"0";//c������Ҫ���0
        b=c+b;//��b����
        for(int i=a.length()-1;i>=0;i--)//��λ����,�Ǵ�a����b��ʼ����Ҫ
        {
            if(a[i]>=b[i]) ans[i]=a[i]-b[i];//һλһλ���м���
            else
            {
                a[i-1]--;//������λ
                ans[i]=a[i]+10-b[i];
            }
        }
        if(!pd) cout<<'-';//�������������
        for(int i=0;i<=b.length()-1;i++)
        {    
            if(bo && ans[i]==0) continue;//������λ�Ͽ���Ϊ0��ֱ������
            else if(ans[i]>0) bo=0;//�ҵ��˲�Ϊ0�����λ
             cout<<ans[i];
        }
        //system("pause");
        return 0;
}
