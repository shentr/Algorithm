// 1005 ( Number Sequence )
//acm.hdu.edu.cn/showproblem.php?pid=1005


#include<iostream>
using namespace std;

//可以用二维数组名作为实参或者形参，在被调用函数中对形参数组定义时可以指定所有维数的大小
//也可以省略第一维的大小说明
//但是不能把第二维或者更高维的大小省略
void matrix_multi(int a[2][2],int b[2][2])
{
    int temp[2][2];
    temp[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%7;
    temp[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%7;
    temp[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%7;
    temp[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%7;
    a[0][0]=temp[0][0],a[0][1]=temp[0][1],a[1][0]=temp[1][0],a[1][1]=temp[1][1];
}

int main()
{
    int a,b,n;
    while(cin>>a>>b>>n&&(a||b||n))
    {
        int m=n;
        int e[2][2]={1,0,
                     0,1};
        int mx[2][2]={a,b,
                      1,0};
        n-=2;
        while(n>0)
        {
            if(n&1)
                matrix_multi(e,mx);
            matrix_multi(mx,mx);
            n/=2;
        }
        if(m<=2)
            cout<<1<<endl;
        else
        cout<<(e[0][0]+e[0][1])%7<<endl;
    }
}
