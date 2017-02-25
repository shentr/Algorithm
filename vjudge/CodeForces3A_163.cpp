// CodeForces3A
//http://codeforces.com/problemset/problem/3A


#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[2][2];
    int d[2][2];
    int c[2];
    int b[8];
    int sum,i;
    cin>>s[0];
    cin>>s[1];
        for(i=0; i<2; i++)
    {
        d[i][0]=s[i][0]-'a'+1;
        d[i][1]=s[i][1]-'0';
    }
    c[0]=d[0][0]-d[1][0];
    c[1]=d[0][1]-d[1][1];
    memset(b,0,sizeof(b));
    sum=0;
    while(c[0]!=0||c[1]!=0)
    {
        if(c[0]>0&&c[1]>0)
        {
            b[0]++;
            c[0]--;
            c[1]--;
            sum++;
        }
        else if(c[0]==0&&c[1]>0)
        {
            b[1]++;
            c[1]--;
            sum++;
        }
        else if(c[0]>0&&c[1]==0)
        {
            b[2]++;
            c[0]--;
            sum++;
        }
        else if(c[0]>0&&c[1]<0)
        {
            b[3]++;
            c[0]--;
            c[1]++;
            sum++;
        }
        else if(c[0]<0&&c[1]>0)
        {
            b[4]++;
            c[0]++;
            c[1]--;
            sum++;
        }
        else if(c[0]<0&&c[1]==0)
        {
            b[5]++;
            c[0]++;
            sum++;
        }
        else if(c[0]==0&&c[1]<0)
        {
            b[6]++;
            c[1]++;
            sum++;
        }
        else if(c[0]<0&&c[1]<0)
        {
            b[7]++;
            c[0]++;
            c[1]++;
            sum++;
        }

    }
    cout<<sum<<endl;
    while(b[0])
    {
        b[0]--;
        cout<<"LD"<<endl;
    }
    while(b[1])
    {
        b[1]--;
        cout<<"D"<<endl;
    }
    while(b[2])
    {
        b[2]--;
        cout<<"L"<<endl;
    }
    while(b[3])
    {
        b[3]--;
        cout<<"LU"<<endl;
    }
    while(b[4])
    {
        b[4]--;
        cout<<"RD"<<endl;
    }
    while(b[5])
    {
        b[5]--;
        cout<<"R"<<endl;
    }
    while(b[6])
    {
        b[6]--;
        cout<<"U"<<endl;
    }
    while(b[7])
    {
        b[7]--;
        cout<<"RU"<<endl;
    }
    return 0;
}
