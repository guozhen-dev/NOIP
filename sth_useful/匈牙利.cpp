#define maxn 10//��ʾx���Ϻ�y�����ж������������
 int nx,ny;//x���Ϻ�y�����ж���ĸ���
 int edge[maxn][maxn];//edge[i][j]Ϊ1��ʾij����ƥ��
 int cx[maxn],cy[maxn];//������¼x������ƥ���yԪ�����ĸ���
 int visited[maxn];//������¼�ö����Ƿ񱻷��ʹ���
 int path(int u)
 {
     int v;
     for(v=0;v<ny;v++)
     {
         if(edge[u][v]&&!visited[v])
         {
             visited[v]=1;
            if(cy[v]==-1||path(cy[v]))//���y�����е�vԪ��û��ƥ�������v�Ѿ�ƥ�䣬���Ǵ�cy[v]���ܹ��ҵ�һ������·
             {
                 cx[u]=v;
                 cy[v]=u;
                 return 1;
             }
         }
     }
     return 0;
 }
 int maxmatch()
 {
     int res=0;
     memset(cx,0xff,sizeof(cx));//��ʼֵΪ-1��ʾ���������ж�û��ƥ���Ԫ�أ�
     memset(cy,0xff,sizeof(cy));
     for(int i=0;i<=nx;i++)
     {
         if(cx[i]==-1)
         {
             memset(visited,0,sizeof(visitited));
             res+=path(i);
         }
     }
     return res;
 }
