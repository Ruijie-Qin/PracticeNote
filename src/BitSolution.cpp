#include "BitSolution.h"
#include <iostream>
using namespace std;

namespace Phoenix
{
    void BitSolution::RunTestCase(BitSolutionEnum solutionType)
    {
        switch (solutionType)
        {
            case BitSolutionEnum::CountingBits:
            {
                auto res = countBits(8);
                for(auto i : res)
                {
                    cout << i << endl;
                }
                break;
            }
        }
    }

    int BitSolution::hammingWeight(uint32_t n) 
    {
        int count = 0;
        while(n)
        {
            count++;
            n &= (n-1);
        }
        return count;
    }

    bool BitSolution::isPowerOfTwo(int n) 
    {
        if (n <= 0)
        {
            return false;
        }
        return (n && ((n&(n-1)) == 0));
    }

    vector<int> BitSolution::countBits(int num) 
    {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++)
        {
            res[i] = res[i&(i-1)] + 1;
            // res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
}
