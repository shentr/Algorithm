// HDU1250
//http://acm.hdu.edu.cn/showproblem.php?pid=1250


#include <iostream>
using namespace std;

const int m=2010;
char data[9000][m+2];

int main()
{
    int i=5,p=m,n,num;
    data[1][m]=1;
    data[2][m]=1;
    data[3][m]=1;
    data[4][m]=1;
    while(data[i-1][1]<=1)
    {
        for(int j=m;j>=p;j--)
        data[i][j]=data[i-1][j]+data[i-2][j]+data[i-3][j]+data[i-4][j];
        for(int j=m;j>=p;j--)
        {
            int c=data[i][j]/10;
            if (c>0)
        {
        data[i][j]=data[i][j]%10;
        data[i][j-1]+=c;
        }
    }
        if (data[i][p-1]>0) p--;
            i++;
}
         while(cin>>n)
         {
            for (int k=0;k<=m;k++)
            if (data[n][k]!=0)
                {num=k;break;}
            for(int k=num;k<=m;k++) cout<<(int)data[n][k];
            cout<<endl;
        }
    return 0;
}
