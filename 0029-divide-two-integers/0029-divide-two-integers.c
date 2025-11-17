int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int negative = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both numbers to positive long long for safe manipulation
    long long dd = llabs((long long) dividend);
    long long dv = llabs((long long) divisor);

    long long result = 0;

    // Subtract divisor from dividend using bit shifting
    while (dd >= dv) {
        long long temp = dv;
        long long multiple = 1;
        // Find max multiple of divisor that fits into dividend
        while (dd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dd -= temp;
        result += multiple;
    }

    // Apply the sign
    return negative * result;
}
