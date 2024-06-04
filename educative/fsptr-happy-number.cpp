#include "SumOfSquaredDigits.cpp"


int squaredSum(int n) {
    int sum = 0;
    while(n > 0) {
        int r = n % 10;
        sum += r * r;
        n = n / 10;
    }
    return sum;
}

bool IsHappyNumber(int n){

    // Replace this placeholder return statement with your code
    int slow = n;
    int fast = n;

    do {
        fast = squaredSum(squaredSum(fast));
        slow = squaredSum(slow);
        if(fast == 1 || slow == 1)
            return true;
        
    }while (slow != fast);
    
    return false;
}
