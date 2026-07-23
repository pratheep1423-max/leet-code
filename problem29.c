int divide(int dividend, int divisor) {
    long long a = dividend;
    long long b = divisor;
    long long result = 0;

    // Determine the sign of the answer
    int negative = (a < 0) ^ (b < 0);

    // Convert both numbers to positive
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    // Subtract using powers of 2
    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    // Apply sign
    if (negative)
        result = -result;

    // Handle 32-bit integer overflow
    if (result > 2147483647)
        return 2147483647;

    if (result < -2147483648LL)
        return -2147483648LL;

    return (int)result;
}
