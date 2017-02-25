// ACdream1188
//http://acdream.info/problem?pid=1188


#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string a,b;
string mp[]={"double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
string nb[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    int n;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        cin>>a>>b;
        cout<<"Case #"<<kase<<":";
        int lena=a.length(),lenb=b.length(),k,last=0;
        string c="";
        for(int i=0;i<=lenb;i++)
        {
            if(i<lenb&&b[i]!='-')
            {
                c+=b[i];
            }
            else
            {
                int lenc=c.length(),num=0,x=1;
                for(int j=0;j<lenc;j++)
                {
                    num+=int(c[lenc-j-1]-'0')*x;
                    x*=10;
                }
                // cout<<"*************"<<num<<endl;
                int cnt=1;
                for(k=last;k<last+num;k++)
                {
                    if(k+1<last+num&&a[k+1]==a[k])
                    {
                        cnt++;
                    }
                    else
                    {
                        int num2=a[k]-'0';
                        if(cnt==1)
                            cout<<" "<<nb[num2];
                        if(cnt>1&&cnt<=10)
                        {
                            cout<<" "<<mp[cnt-2]<<" "<<nb[num2];
                        }
                        if(cnt>10)
                        {
                            while(cnt--)
                                cout<<" "<<nb[num2];
                        }
                        cnt=1;
                    }
                }
                last=k;
                c="";
            }
        }
        cout<<endl;
    }
}

/*
3
15012233444 3-4-4
15012233444 3-3-5
12223 2-3
*/
