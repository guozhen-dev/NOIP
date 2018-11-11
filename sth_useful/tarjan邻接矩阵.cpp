#include<iostream>
using namespace std;
int DFN[105];                                  //��¼����dfsʱ�ڵ����������
int low[105];                                  //��¼�ڵ��ܹ��ҵ������ȷ��ʵ����ȵļǺ�
int count=1;                                   //��Ƿ��ʴ���ʱ���
int stack[105];                                //ѹ��ջ��
int top=-1;
int flag[105];                                 //��ǽڵ��Ƿ��Ѿ���ջ��
int number=0;
int j;
int matrix[105][105]={{0,1,1,0,0,0},{0,0,0,1,0,0},{0,0,0,1,1,0},{1,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,0,0,0}};
int length;                                    //ͼ�ĳ���
void tarjan(int u){
    DFN[u]=low[u]=count++;                     //��ʼ������ֵ���Լ�Ϊ���ҵ������ȷ��ʵ�����
    stack[++top]=u;
    flag[u]=1;                                 //���Ϊ�Ѿ���ջ��
 
    for(int v=0;v<length;v++){
	if(matrix[u][v]){
	    if(!DFN[v]){                       //�����iû�б����ʹ�
		tarjan(v);                     //�ݹ����
		if(low[v]<low[u])
		    low[u]=low[v];             //�������ҵĵ�����
	    }
	    else{                              //������ʹ��ˣ����Ҹõ��DFN��С����
		if(DFN[v]<low[u]&&flag[v])     //flag[v]����ж���������Ҫ���������Ա����Ѿ�ȷ����������ͨͼ��v,��Ϊu��v�ĵ���߶�Ӱ�쵽u��low
		low[u]=DFN[v];                 //Ҳ�����Ѿ�ȷ���˵���ͨͼҪ�޳������޳��İ취�����ж��仹��ջ�У���Ϊ�Ѿ�ȷ���˵���ͨͼ�ĵ�
	    }                                  //flag�������do while���Ѿ���Ϊ0��(���Ѿ���ջ���޳���)
	}
    }
 
    //������ݵ�ʱ���������DFN��low��ͬ�Ľڵ㣬�Ϳ��԰�����ڵ�֮��Ľڵ�ȫ����ջ��������ͨͼ
    if(DFN[u]==low[u]){
	number++;                               //��¼��ͨͼ������
	do{
	    j=stack[top--];                     //����ȡ����ֱ��u
	    cout<<j<<" ";
	    flag[j]=0;                          //����Ϊ����ջ��
	}while(j!=u);
	    cout<<endl;
    }
}
int main(){
	
    memset(DFN,0,sizeof(DFN));                  //���ݵĳ�ʼ��
    memset(low,0,sizeof(low));
    memset(flag,0,sizeof(flag));
	
    length=6;
    tarjan(0);
 
    cout<<endl;
    for(int i=0;i<6;i++){
	cout<<"DFN["<<i<<"]:"<<DFN[i]<<" low["<<i<<"]:"<<low[i]<<endl;
    }
    return 0;
}
