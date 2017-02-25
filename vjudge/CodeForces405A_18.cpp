// CodeForces405A
//http://codeforces.com/problemset/problem/405A


 #include<iostream>
 #include<cstdio>
 #include<algorithm>
 using namespace std;

 int main()
 {
     int n;
     int a[105];
     while(cin>>n)
     {
         for(int i=0;i<n;i++)
         {
             cin>>a[i];
         }
         sort(a,a+n);
         cout<<a[0];
         for(int i=1;i<n;i++)
            cout<<" "<<a[i];
        cout<<endl;
     }
 }
