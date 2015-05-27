// leetcode 204 Count Primes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        bool * array = new bool[n];
        int i, prime, counter = 0;

        for (i = 2; i < n; i++)
            array[i] = true;

        for (prime = 2; prime * prime < n; ) {
            for (i = prime * 2; i < n; i += prime)
                array[i] = false;
 
            for (i = prime + 1; i * i < n; i++)
                if (array[i])
                    break;

            prime = i;
        }

        for (i = 2; i < n; i++)
            if (array[i])
                counter++;

        return counter;
    }
};
