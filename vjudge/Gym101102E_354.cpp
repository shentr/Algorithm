// Gym101102E
//undefined101102E


#include <iostream>

using namespace std;

int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int m=n%5;
        int l=n/5;
        if(m!=0)
            m=1;
        cout<<m+l<<endl;
    }
    return 0;
}
