// CodeForces389B
//http://codeforces.com/problemset/problem/389B


#include <iostream>
#include <stdio.h>
using namespace std;
int a[105][105];
int main()
{
    int n;
    while(cin>>n)
    {
        getchar();
        int sum=0,num=0,t=0;
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<n; j++)
            {
                scanf("%c",&a[i][j]);
            }
             getchar();

        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(a[i][j]=='#')
            {
                sum++;
            }
        }
       // cout<<sum<<endl;
        t=sum/5;
        if(sum==0)
            cout<<"YES"<<endl;
        else if(sum%5!=0)
            cout<<"NO"<<endl;
        else
        {
            for(int i=1;i<n;i++)
                for(int j=1;j<n;j++)
            {
                if(a[i][j]=='#'&&a[i-1][j]=='#'&&a[i][j-1]=='#'&&a[i+1][j]=='#'&&a[i][j+1]=='#')
                {
                    num++;
                    a[i][j]='.';
                    a[i][j-1]='.';
                    a[i-1][j]='.';
                    a[i+1][j]='.';
                    a[i][j+1]='.';

                }
            }
          //  cout<<num<<" "<<sum<<endl;
        if(num==t)
            cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

        }

    }
    return 0;
}
