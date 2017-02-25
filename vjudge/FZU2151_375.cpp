// FZU2151
//http://acm.fzu.edu.cn/problem.php?pid=2151


#include <iostream>
#include <string.h>
using namespace std;
char s[105][105];
int main()
{
    int T,n,m;
    cin>>T;
     int k=0;
    while(T--)
    {
        memset(s,0,sizeof(s));

        int sum=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>s[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(s[i][j]=='O')
                sum++;
        }
        cout<<"Case "<<++k<<": ";
        if(sum%2==0)
            cout<<"Fat brother"<<endl;
        else cout<<"Maze"<<endl;
    }
    return 0;
}
