inline int read(){//非常重要的快速读入代码
    int x=0,sign=1;
    char c=getchar();
    while(c>'9'||c<'0'){//判断符号
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){//转换数
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
