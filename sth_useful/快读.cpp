inline int read(){//�ǳ���Ҫ�Ŀ��ٶ������
    int x=0,sign=1;
    char c=getchar();
    while(c>'9'||c<'0'){//�жϷ���
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){//ת����
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
