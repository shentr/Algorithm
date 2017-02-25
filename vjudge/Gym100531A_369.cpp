// Gym100531A
//undefined100531A


#include <bits/stdc++.h>

using namespace std;
int a[15];
int n;
int main()
{
    ifstream fin("alarm.in");
    ofstream fout("alarm.out");
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    while(fin>>n)
    {
          bool flag=0;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=9;j++)
            {
                for(int k=0;k<=5;k++)
                {
                    for(int l=0;l<=9;l++)
                    {

                        if(i!=2)
                        {
                            if(a[i]+a[j]+a[k]+a[l]==n)
                            {
                                fout<<i<<j<<":"<<k<<l<<endl;
                                flag=1;
                                break;
                            }
                        }
                        else if(i==2&&j<=5)
                        {
                            if(a[i]+a[j]+a[k]+a[l]==n)
                            {
                                fout<<i<<j<<":"<<k<<l<<endl;
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag)
                        break;
                }
                if(flag)
                        break;
            }
            if(flag)
                        break;
        }
        if(!flag)
            fout<<"Impossible"<<endl;
    }
    return 0;
}
