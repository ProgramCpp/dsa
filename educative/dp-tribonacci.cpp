int FindTribonacci(int n)
{
    vector<int> fib(n + 1 , 0);

    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= n; i++) {
        // can still be optimized. 'n' array is not needed. only the last 3 variables
        fib[i] = fib[i-1] + fib[i-2] + fib[i-3];
    }

    return fib[n];
}