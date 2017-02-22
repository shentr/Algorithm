// 2098 ( 分拆素数和 )
//acm.hdu.edu.cn/showproblem.php?pid=2098


#include<iostream>
using namespace std;
int main()
{
    
    int sushu(int n);
    int oushu,i,count;
    while(cin>>oushu&&oushu)
    {
       count=0;
        for (i=2;i<oushu/2;i++)
        {
         if(sushu(i)&&sushu(oushu-i))
         count++;
        }
        cout<<count<<endl;
    }  
    return 0;        
}

int sushu(int n)
{
    int j,d=0;
    for(j=2;j*j<=n;j++)
    {if(n%j==0)
    {return (0);
    d=1;break;
    }
    }
    if(d==0)
    return (1);
}
