// CodeForces404A
//http://codeforces.com/problemset/problem/404A


#include <iostream>
#include <stdio.h>
using namespace std;
char a[305][305];
int main()
{
    char s2,s1;
    int n;
    while(cin>>n)
    {
        int sum1=0,sum2=0,sum3=0;
        for(int i=0;i<n;i++)
        {
            getchar();
            for(int j=0;j<n;j++)
            {
                scanf("%c",&a[i][j]);
            }
        }

            s1=a[0][0];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
            {
                if(i==j&&a[i][j]==s1)
                    sum1++;
                else if(i+j+1==n&&a[i][j]==s1)
                    sum1++;
                else if(i!=j&&i+j!=n-1)
                {
                    if(a[0][1]==a[0][0])
                        {
                            //cout<<"NO"<<endl;
                            //break;
                            sum3++;
                        }
                    else
                    {
                        s2=a[0][1];
                        if(a[i][j]==s2)
                            sum2++;
                        else if(a[i][j]!=s2&&a[i][j]!=a[0][0])
                        {
                            //cout<<"NO"<<endl;
                          //  break;
                          sum3++;
                        }
                    }
                }
            }

           if(sum1+sum2==n*n)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

    }

    return 0;
}