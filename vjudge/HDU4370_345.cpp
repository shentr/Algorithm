// HDU4370
//http://acm.hdu.edu.cn/showproblem.php?pid=4370


    #include<iostream>
    #include<cstring>
    #include<cstdlib>
    #include<queue>
    #include<cstdio>
    using namespace std;
    int n,m,x;
    const long long  MAXINT=0x3f3f3f3f;
    const int MAXNUM=609;
    long long dist[MAXNUM];
    long long A[MAXNUM][MAXNUM];
    void Dijkstra(int v0)
    {
        bool S[MAXNUM];// 判断是否已存入该点到S集合中
        for(int i=1; i<=n; ++i)
        {
            dist[i]=A[v0][i];
           // printf("%d    ",dist[i]);
            S[i]=false; // 初始都未用过该点
        }
       // dist[v0] = 0;
        S[v0]=true;
        for(int i=2; i<=n; i++)
        {
            long long mindist = MAXINT;
            int u = -1;// 找出当前未使用的点j的dist[j]最小值
            for(int j=1; j<=n; ++j)
            if((!S[j]) && dist[j]<mindist)
            {
                u = j;// u保存当前邻接点中距离最小的点的号码
                mindist = dist[j];
                //printf("%d        ",mindist);
            }
            S[u] = true;
            for(int j=1; j<=n; j++)
                if((!S[j]) && A[u][j]<MAXINT)
                {
                    if(dist[u] + A[u][j] < dist[j])     //在通过新加入的u点路径找到离v0点更短的路径
                    {
                        dist[j] = dist[u] + A[u][j];    //更新dis                    //记录前驱顶点
                    }
                }
        }
        return;
    }
    int main()
    {
       //freopen("in.txt","r",stdin);
        while(~scanf("%d",&n))
        {
            for(int i=1; i<=n*2; i++)
            {
                for(int j=1; j<=n*2; j++)
                    if(i-j==n) A[i][j]=0;
                    else A[i][j]=MAXINT;
            }
            for(int i=1;i<=n;i++)
                for(int j=1+n;j<=n*2;j++)
                    scanf("%I64d",&A[i][j]);
            A[1][n+1]=A[n][n+n]=MAXINT;
            A[n+1][n]=0;
           // A[1][1+n]=A[n][n*2]=MAXINT;
          //  for(int i=1;i<=2*n;i++)for(int j=1;j<=2*n;j++)printf("i=%d,j=%d,A=%d\n",i,j,A[i][j]);
            n=n+n;
            Dijkstra(1);
            //for(int i=n/2+1;i<=n;i++)
            printf("%I64d\n",dist[n]);
        }
        return 0;
    }
