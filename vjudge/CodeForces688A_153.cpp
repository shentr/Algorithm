// CodeForces688A
//http://codeforces.com/problemset/problem/688A


#include <iostream>

using namespace std;
string s;
int main()
{
    int n,d;
    while(cin>>n>>d)
    {
        int tmp=0,sum=0;
        for(int k=1; k<=d; k++)
        {
            cin>>s;
            bool flag=0;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='0')
                    flag=1;
            }
            if(flag==1)
                tmp++;
            else tmp=0;
            sum=max(tmp,sum);
        }
        cout<<sum<<endl;
    }
}
