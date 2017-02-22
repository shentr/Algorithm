// 1171 ( Big Event in HDU )
//acm.hdu.edu.cn/showproblem.php?pid=1171


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 110000;
int a[MAX],len,n;
int main()
{
    while(cin >> n && n >= 0){
        memset(a,0,sizeof(a));
        int num,value,sum = 0;
        len = 0;
        for(int i=0;i<n;i++){
            cin >> value >> num;
            sum += value * num;
            while(num--)
                a[len++] = value;
        }
        sort(a,a+len);
        int half = sum / 2;
        num = 0;
        for(int i=len-1;i>=0;i--){
            if(num + a[i] > half)
                continue;
            num += a[i];
        }
        cout << sum - num << " " << num << endl;
    }
    return 0;
}