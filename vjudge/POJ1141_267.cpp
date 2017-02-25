// POJ1141
//http://poj.org/problem?id=1141


#include <iostream>
#include <string.h>
using namespace std;
string s;
int pos[105][105],dp[105][105];
void show(int i,int j)
{
    if(i>j)
        return;
    if(i==j)
    {
        if(s[i]=='('||s[i]==')')
            cout<<"()";
        else cout<<"[]";
    }
    else
        {
            if(pos[i][j]==-1)
            {
                cout<<s[i];
                show(i+1,j-1);
                cout<<s[j];
            }
            else
            {
                show(i,pos[i][j]);
                show(pos[i][j]+1,j);
            }
        }
}
int main()
{
    while(getline(cin,s))
    {
        memset(dp,0,sizeof(dp));
        memset(pos,0,sizeof(pos));
        for(int i=1;i<s.size();i++)
            for(int j=0,k=i;k<s.size();j++,k++)
        {
            if(s[j]=='('&&s[k]==')'||s[j]=='['&&s[k]==']')
            {
                dp[j][k]=dp[j+1][k-1]+2;
                pos[j][k]=-1;
            }
            for(int m=j;m<k;m++)
            {
                if(dp[j][m]+dp[m+1][k]>=dp[j][k])
                  {
                      dp[j][k]=dp[j][m]+dp[m+1][k];
                pos[j][k]=m;
                  }
            }
        }
        show(0,s.size()-1);
        cout<<endl;
         s.clear();

    }
    return 0;
}
