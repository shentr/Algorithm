// HDU1021
//http://acm.hdu.edu.cn/showproblem.php?pid=1021


#include<iostream>
using namespace std;
const int MOD=3;

struct matrix
{
    int m[2][2];
};

matrix p={1,1,
          1,0};
matrix e={1,0,
          0,1};

matrix mtx_mul(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
    {
        c.m[i][j]=0;
        for(int k=0;k<2;k++)
            c.m[i][j]+=a.m[i][k]*b.m[k][j]%MOD;
            c.m[i][j]%=MOD;
    }
    return c;
}

matrix mtx_quickpow(int n)
{
    matrix a=p,b=e;
    while(n>=1)
    {
        if(n&1)
        b=mtx_mul(a,b);
    n>>=1;
    a=mtx_mul(a,a);
    }
    return b;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            cout<<"no"<<endl;
        else if(n==1)
            cout<<"no"<<endl;
        else
        {
            matrix c=mtx_quickpow(n-1);
            if((c.m[0][0]*11+c.m[0][1]*7)%MOD==0)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
}
