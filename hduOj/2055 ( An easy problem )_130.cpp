// 2055 ( An easy problem )
//acm.hdu.edu.cn/showproblem.php?pid=2055


#include<iostream>

int main()
{
    using namespace std;
    int number,T;
    char letter;
    cin>>T;
    while(T--)
    {
        cin>>letter>>number;
        if(letter>=65&&letter<=90)
            letter=letter-64;
        else if(letter>=97&&letter<=122)
            letter=96-letter;
        cout<<letter+number<<endl;
    }
    return 0;
}
