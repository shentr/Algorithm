// CodeForces416A
//http://codeforces.com/problemset/problem/416A


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 0x3f3f3f3f
int main()
{
    int n;
    cin>>n;
    int p=M,q=-M;
    string s1,s2;
    int num;
    while(n--)
    {
        cin>>s1>>num>>s2;
        if(s1==">="&&s2=="Y")
        {
            if(q<num)
                q=num;
        }
        else if(s1==">"&&s2=="Y")
        {
            if(q<=num)
                q=num+1;
        }
        else if(s1=="<="&&s2=="Y")
        {
            if(p>num)
                p=num;
        }
        else if(s1=="<"&&s2=="Y")
        {
            if(p>=num)
                p=num-1;
        }
        else if(s1==">="&&s2=="N")
        {
            if(p>=num)
                p=num-1;
        }
        else if(s1==">"&&s2=="N")
        {
            if(p>num)
                p=num;
        }
        else if(s1=="<="&&s2=="N")
        {
            if(q<=num)
                q=num+1;
        }
        else if(s1=="<"&&s2=="N")
        {
            if(q<num)
                q=num;
        }
    }
    if(p<q)
        cout<<"Impossible"<<endl;
    else
        cout<<q<<endl;

return 0;
}
