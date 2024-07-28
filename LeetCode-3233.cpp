class Solution {
public:
    vector<bool> sieve(int max) {
        vector<bool> isPrime(max + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= max; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int nonSpecialCount(int l, int r) {
        int maxSqrt = static_cast<int>(sqrt(r)) + 1;
        vector<bool> isPrime = sieve(maxSqrt);

        int specialCount = 0;
        for (int i = 2; i <= maxSqrt; ++i) {
            if (isPrime[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    ++specialCount;
                }
            }
        }

        int totalNumbers = r - l + 1;
        return totalNumbers - specialCount;
    }
};