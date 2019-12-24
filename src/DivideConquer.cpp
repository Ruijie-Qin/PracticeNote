#include "DivideConquer.h"
#include <iostream>
using namespace std;

namespace Phoenix
{
    void DivideConquerSolution::RunTestCase(DivideConquerSolutionEnum solutionType)
    {
        switch (solutionType)
        {
            case DivideConquerSolutionEnum::PowN:
            {
                cout << myPow_2(-2, 9) << endl;
                cout << myPow_2(-2, -4) << endl;
                int n =  -2147483648;
                long long N = -n;
                cout << N << endl;
                for (int i = 1; i < 20; i++)
                {
                    N >>= 1;
                    cout << N << endl;
                }
                cout << myPow_2(2, -2147483648) << endl;
                break;
            }
            default:
                break;
        }
    }

    double DivideConquerSolution::myPow_1(double x, int n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        // 如果按照下面的方式写，当x=-2147483648时，-x的值仍然是-2147483648
        // if (n < 0)
        // {
        //     x = 1/x;
        //     n = -n;
        // }
        if (n == -1)
        {
            return 1/x;
        }

        double y = myPow_1(x, n/2);
        if (n % 2 == 0)
        {
            return y*y;
        }
        else
        {
            return y*y*(n > 0 ? x : 1/x);
        }
    }
    // 非递归写法
    double DivideConquerSolution::myPow_2(double x, int n)
    {
        long long N = n;
        if (n < 0)
        {
            x = 1/x;
            N = -N;
        }

        double pow = 1;
        while (N)
        {
            if ((N & 1) == 1)
            {
                pow *= x;
            }
            x *= x;
            N >>= 1;
        }
        return pow;
    }
}
 