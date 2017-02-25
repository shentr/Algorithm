// Gym100801E
//undefined100801E


#include"bits/stdc++.h"

using namespace std;
string s;
int main()
{
    ifstream fin("easy.in");
    ofstream fout("easy.out");
    while(fin>>s)
    {
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='+')
            {
                fout<<s[i];
                int k=i+1;
                while(s[k]!='+'&&s[k]!='-'&&i<s.length())
                {
                    fout<<s[k++];
                    i=k;
                }
            }
            else if(s[i]=='-')
            {
                fout<<s[i]<<s[i+1];
                //int k=i+2;
                i=i+2;
                bool flag=0;
                while(i<s.length()&&s[i]!='-'&&s[i]!='+')
                {
                    if(s[i]=='+'||s[i]=='-')
                        break;
                    if(s[i]=='0')
                    {
                        fout<<'+';
                        fout<<s[i++];
                        //i=k;
                        //cout<<k<<endl;
                    //break;
                    }

                    else if(s[i]>='1'&&s[i]<='9')
                    {
                            fout<<'+';
                        while(i<s.length()&&s[i]!='+'&&s[i]!='-')
                            fout<<s[i++];
                    }
                   // else break;

                }
            }
            else
                fout<<s[i++];
        }
        fout<<endl;
    }
    return 0;
}
