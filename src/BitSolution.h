#include <cstdint>
#include <vector>
using namespace std;

namespace Phoenix
{
    enum BitSolutionEnum
    {
        CountingBits = 1,
    };
    class BitSolution
    {
    public: 
        void RunTestCase(BitSolutionEnum solutionType);
        /// 191. Number of 1 Bits
        int hammingWeight(uint32_t n);
        /// 231. Power of Two
        bool isPowerOfTwo(int n);
        /// 338. Counting Bits
        vector<int> countBits(int num);
    };
}