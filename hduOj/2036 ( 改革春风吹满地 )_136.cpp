// 2036 ( 改革春风吹满地 )
//acm.hdu.edu.cn/showproblem.php?pid=2036


//S = 0.5 * ( (x0*y1-x1*y0) + (x1*y2-x2*y1) + ... + (xn*y0-x0*yn) )
#include <math.h>
#include <stdio.h>

int main(void)
{
    int x[3], y[3], n;
    double sum;

    while (scanf("%d", &n), n)
    {
        scanf("%d%d", x, y);
        x[2] = x[0]; y[2] = y[0];
        sum = 0.0;
        while (--n)
        {
            scanf("%d%d", x+1, y+1);
            sum += x[0]*y[1] - x[1]*y[0];
            x[0] = x[1]; y[0] = y[1];
        }
        sum += x[0]*y[2] - x[2]*y[0];
        printf("%.1f\n", sum / 2.0);
    }

    return 0;
}
