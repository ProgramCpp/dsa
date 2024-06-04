// int ClimbStairs(int n)
// {   
//     if(n <= 0)
//         return 0;
    
//     if (n == 1)
//         return 1;

//     if (n == 2)
//         return 2;

//     return ClimbStairs(n-1) + ClimbStairs(n-2);
// }

int ClimbStairs(int n)
{                   
    int climbs[n + 1];
    climbs[0] = 0;                                              
    climbs[1] = 1;
    climbs[2] = 2;

    for(int i = 3; i <= n; i++){
        climbs[i] = climbs[i-1] + climbs[i-2];
    }

    return climbs[n];
}


