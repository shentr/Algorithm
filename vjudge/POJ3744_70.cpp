// POJ3744
//http://poj.org/problem?id=3744


#include"stdio.h"
#include"string.h"
#include"algorithm"
#include"iostream"
#include"math.h"
using namespace std;
int a[30];

struct Matrix
{
    double ma[2][2];
};

Matrix mult(Matrix a,Matrix b)
{
    Matrix ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans.ma[i][j]=0;
            for(int k=0;k<2;k++)
                ans.ma[i][j]+=a.ma[i][k]*b.ma[k][j];
        }
    }

    return ans;
}

Matrix pow_M(Matrix a,int n)
{
    Matrix ans;
    memset(ans.ma,0,sizeof(ans.ma));
    for(int i=0;i<2;i++)
        ans.ma[i][i]=1;
    Matrix tmp=a;
    while(n)
    {
        if(n&1)
            ans=mult(ans,tmp);
        tmp=mult(tmp,tmp);
        n>>=1;
    }
    return ans;
}

int main()
{
    int n;
    double p;
    while(cin>>n>>p)
    {
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        sort(a,a+n);
        double ans=1.0;
        Matrix fs;
        fs.ma[0][0]=p,fs.ma[0][1]=1-p,fs.ma[1][0]=1,fs.ma[1][1]=0;
        Matrix tmp;
        tmp=pow_M(fs,a[0]-1);
        ans*=(1-tmp.ma[0][0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                continue;
            tmp=pow_M(fs,a[i]-a[i-1]-1);
            ans*=(1-tmp.ma[0][0]);
        }
        printf("%.7lf\n",ans);
    }
    return 0;
}
