class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;

        if (n >= 1000)
            total_commas += n - 1000 + 1;

        if (n >= 1000000)
            total_commas += n - 1000000 + 1;

        if (n >= 1000000000)
            total_commas += n - 1000000000LL + 1;

        if (n >= 1000000000000LL)
            total_commas += n - 1000000000000LL + 1;

        if (n >= 1000000000000000LL)
            total_commas += n - 1000000000000000LL + 1;

        return total_commas;
    }
};