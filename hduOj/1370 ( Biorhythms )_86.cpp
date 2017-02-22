// 1370 ( Biorhythms )
//acm.hdu.edu.cn/showproblem.php?pid=1370


#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int i, n, t, k1, k2;
    int days;
    int p, e, d;
    cin >> n;
    while (cin >> p >> e >> i >> d && p != -1 && i != -1 && e != -1 && d != -1) {
        t = 23;
        k1 = p - e;
        k2 = p - i;
        while (1) {
            if ((t + k1) % 28 == 0 && (t + k2) % 33 == 0)
                break;
            t += 23;
        }
        days = t + p - d;
        if (days <= 0) {//小于0，寻找下一个高潮点
            t += 23;
            while (1) {
                if ((t + k1) % 28 == 0 && (t + k2) % 33 == 0)
                    break;
                t += 23;
            }
            days = t + p - d;
        }
        cout << "Case " << n++ << ": the next triple peak occurs in " << days
                << " days." << endl;
        ;

    }
    return 0;
}
