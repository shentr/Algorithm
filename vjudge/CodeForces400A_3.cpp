// CodeForces400A
//http://codeforces.com/problemset/problem/400A


#include<iostream>
#include<cstdio>
using namespace std;
char a[15];

bool is_1_12()
{
    for(int i=1;i<=12;i++)
    {
        if(a[i]=='X')
            return true;
    }
    return false;
}

bool is_2_6()
{
    for(int i=1;i<=6;i++)
        if(a[i]==a[i+6]&&a[i]=='X')
        return true;
    return false;
}

bool is_3_4()
{
    for(int i=1;i<=4;i++)
        if(a[i]==a[i+4]&&a[i]==a[i+8]&&a[i]=='X')
        return true;
    return false;
}

bool is_4_3()
{
    for(int i=1;i<=3;i++)
        if(a[i]==a[i+3]&&a[i]==a[i+6]&&a[i]==a[i+9]&&a[i]=='X')
        return true;
    return false;
}

bool is_6_2()
{
    for(int i=1;i<=2;i++)
        if(a[i]==a[i+2]&&a[i]==a[i+4]&&a[i]==a[i+6]&&a[i]==a[i+8]&&a[i]==a[i+10]&&a[i]=='X')
        return true;
    return false;
}

bool is_12_1()
{
    for(int i=1;i<=12;i++)
    {
        if(a[i]=='O')
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int count=0;
        for(int i=1;i<=12;i++)
            cin>>a[i];
        //getchar();      ///
        if(is_1_12()) count++;
        if(is_2_6()) count++;
        if(is_3_4()) count++;
        if(is_4_3()) count++;
        if(is_6_2()) count++;
        if(is_12_1()) count++;
        cout<<count;
        if(is_1_12()) cout<<" 1x12";
        if(is_2_6())  cout<<" 2x6";
        if(is_3_4()) cout<<" 3x4";
        if(is_4_3()) cout<<" 4x3";
        if(is_6_2()) cout<<" 6x2";
        if(is_12_1()) cout<<" 12x1";
        cout<<endl;
    }
}
