// UVA10815
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10815


#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string>jihe;
int main()
{
    string s;
    while(getline(cin,s))
    {
        string tmp;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]=s[i]+32;
                tmp+=s[i];
                //cout<<s[i]<<" "<<tmp<<endl;
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                tmp+=s[i];
            }
            //if(s[i]==' ')
            else
            {
                if(!tmp.empty())
                {
                    jihe.insert(tmp);
                //cout<<tmp<<endl;
                tmp.clear();
                }
            }
        }
        if(!tmp.empty())
            jihe.insert(tmp);

    }
    for(set<string>::iterator it=jihe.begin();it!=jihe.end();it++)
        {
            cout<<*it<<endl;
        }

    return 0;
}
