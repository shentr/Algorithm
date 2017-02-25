// HDU4811
//http://acm.hdu.edu.cn/showproblem.php?pid=4811


#include <iostream>

using namespace std;

int main()
{
    long long a,b,c;
   while(cin>>a>>b>>c)
   {
       long long aa=0,bb=0,cc=0;
       long long sum=0;
       if(a>=2&&b>=2&&c>=2)
       sum=15+(a-2+b-2+c-2)*6;
       /*else if((a==0&&b==0&&c==0)||(a==0&&b==0&&c==1)||(a=0&&b==1&&c==0)||(a==1&&b==0&&c==0))
        sum+=0;

       else if(a==1&&b==1&&c==1)
        sum+=3;
       else if((a==0&&b==0&&c==2)||(a==2&&b==0&&c==0)||(a==0&&b==2&&c==0))
        sum+=2;
        else if(a+b+c==2)
        sum+=1;
        else if((a==0&&b==0&&c>2)||(a>2&&b==0&&c==0)||(a==0&&b>2&&c==0))
        {
            sum+=(a+b+c-2)*2+1;
        }*/
        else
        {
           aa=a<2?a:2;
            bb=b<2?b:2;
            cc=c<2?c:2;
          //cout<<aa<<" "<<bb<<" "<<cc<<endl;
          //cout<<a<<" "<<b<<" "<<c<<endl;
            sum=(a+b+c-aa-bb-cc)*(aa+bb+cc)+(aa+bb+cc-1)*(aa+bb+cc)/2;
        }
        cout<<sum<<endl;


   }
    return 0;
}
