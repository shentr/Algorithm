// LightOJ1229
//http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1229


#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int sg[205];
int vis[205];
void init()
{
	int i,j,k;
	sg[0]=0;
	sg[1]=sg[2]=sg[3]=1;
	for(i=4;i<=200;i++)
	{
		memset(vis,0,sizeof(vis));
		for(j=3;j<=5&&i-j>=0;j++)
		vis[sg[i-j]]=1;
		for(j=6;i-j>=0;j++)
		vis[sg[j-5]^sg[i-j]]=1;
		for(j=max(i-5,0);j<=i-3;j++)
        vis[sg[j]]=1;
		for(j=0;j<=200;j++)
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
	}
}

int e[202],f[202],g[202],n;
int find()
{
    int s=0,i,j,k=0;
    for(i=0;i<n;i++)
    {
        if(f[i]==0)
            k++;
        else
        {
            s=s^sg[k];
            k=0;
        }
    }
    s=s^sg[k];
    return s;
}

int main()
{
    init();
    char a[205];
    int T;
    cin>>T;
    for(int kase=1;kase<=T;kase++)
    {
        cin>>a;
        int i,j,k,flag=0,t=0;
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(i<n-2&&a[i+1]=='X'&&a[i+2]=='X'){flag=1;e[t++]=i;}
            else if(i>0&&a[i-1]=='X'&&a[i+1]=='X'){flag=1;e[t++]=i;}
            else if(i>1&&a[i-1]=='X'&&a[i-2]=='X'){flag=1;e[t++]=i;}
        }
        if(flag)
        {
            printf("Case %d:",kase);
            for(i=0;i<t;i++)
                cout<<" "<<e[i]+1;
            cout<<endl;
        }
        else
        {
            memset(g,0,sizeof(g));
            for(i=0;i<n;i++)
                if(a[i]=='X')
                {
                    for(j=i-2;j<=i+2;j++)
                        if(j>=0&&j<n)
                        g[j]=1;
                }
            memcpy(f,g,sizeof(f));
            if(find()==0)
            {
                printf("Case %d: 0\n",kase);
                continue;
            }
            for(i=0;i<n;i++)
            {
                if(g[i]==0)
                {
                    memcpy(f,g,sizeof(f));
                    for(j=i-2;j<=i+2;j++)
                        if(j>=0&&j<n)
                        f[j]=1;
                    if(find()==0)
                        e[t++]=i;
                }
            }
            printf("Case %d:",kase);
            for(i=0;i<t;i++)
                cout<<" "<<e[i]+1;
            cout<<endl;
        }
    }
    return 0;
}
