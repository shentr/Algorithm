// UVA156
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=156


#include <iostream>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    string str[1025],str2[1025];
    int k=0;
    map<string,int>hashs;
    set<string>jihe;
    while(getline(cin,s))
    {
        if(s[0]=='#')
            break;
        string tmp;
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            {
                tmp+=s[i];
            }
            else
            {
                if(!tmp.empty())
                {
                    str[k++]=tmp;
                    tmp.clear();
                }
            }
        }
        if(!tmp.empty())
        {
            str[k++]=tmp;
            tmp.clear();
        }
    }
        //cout<<"****"<<endl;
        /*for(int kk=0; kk<k; kk++)
        {
            for(int j=0; j<str[kk].size(); j++)
            {
                if(str[kk][j]>='A'&&str[kk][j]<='Z')
                {
                    str2[kk][j]=str[kk][j]+32;
                    cout<<str[kk][j]<<" 1 "<<str2[kk][j]<<endl;
                    //cout<<100<<endl;
                    //cout<<<<endl;
                }
                else if(str[kk][j]>='a'&&str[kk][j]<='z')
                {
                    str2[kk][j]=str[kk][j];
                    cout<<str[kk][j]<<" 2 "<<str2[kk][j]<<endl;
                    //cout<<str[kk][j]<<endl;
                    //cout<<str2[kk][j]<<endl;
                }
                cout<<str2[kk]<<" 4444 "<<endl;
            }//cout<<str2[kk]<<endl;
            cout<<str[kk]<<" 3333  "<<endl;
            sort(str2[kk].begin(),str2[kk].end());

            hashs[str2[kk]]++;
        }*/
        string tmp2;
        for(int kk=0;kk<k;kk++)
        {
            for(int j=0; j<str[kk].size(); j++)
            {
                if(str[kk][j]>='A'&&str[kk][j]<='Z')
                {
                    tmp2+=str[kk][j]+32;
                }
                else if(str[kk][j]>='a'&&str[kk][j]<='z')
                {
                    tmp2+=str[kk][j];
                }
            }
            str2[kk]=tmp2;
            //cout<<tmp2<<" 100 "<<str2[kk]<<endl;
            tmp2.clear();
            sort(str2[kk].begin(),str2[kk].end());
            //cout<<str2[kk]<<endl;
            hashs[str2[kk]]++;
        }
        for(int kk=0; kk<k; kk++)
        {
            //cout<<hashs[str2[kk]]<<"****"<<str2[kk]<<"***"<<str[kk]<<endl;
            if(hashs[str2[kk]]==1)
            {
                jihe.insert(str[kk]);
            }
        }
        for(set<string>::iterator it=jihe.begin(); it!=jihe.end(); it++)
        {
            cout<<*it<<endl;
        }

    return 0;
}
/**
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
ladder came tape soon leader acme RIDE lone Dreis peat ScAlE orb eye Rides dealer NotE derail LaCeS drIed noel dire Disk mace Rob dries
#
*/
