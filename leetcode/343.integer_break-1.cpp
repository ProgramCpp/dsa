/* 343. Integer Break
intuition: u only neeed to return the product. bigger number gives bigger product? what about n/2?
ex: 10: 5 + 5 = 10. 5 * 5 = 25. 36 is the answer (3 + 3 + 4)
more k numbers, bigger the product.
Hint 1
For all x, y >1, product(x,y) ≥ sum(x,y)
Hint 2
It follows that it always makes sense to try to split the sum into the most components > 1 possible, as product > sum
Hint 3
2 and 3 sum up to any number ≥ 2*, so it always makes sense to break it down into 2s and 3s. The optimal answer will be comprised of only 2s and 3s
*(you can trivially prove this because 1 and 2 sum up to every number, and 3 is 2+1)
17

ex: 45: 22 + 23. 22 * 23 = 506. but, 3^15 = 14,348,907
i.e, break down n into max **no** of 3's.
*/


// trying dp solution
// accepted. u can cache max product for every n value too.
class Solution {
public:
    int ib(int n){
        if( n == 1)
            return -1; // reduce max prod

        if(n == 2)  
            return 2;

        if(n == 3)
            return 3;

        return max(ib(n - 3) * 3, ib(n - 2) * 2);
    }

    int integerBreak(int n) {
        if(n == 2)
            return 1;

        if(n == 3)
            return 2;

        return ib(n);
    }
};


// accepted, mathematical
// class Solution {
// public:
//     int integerBreak(int n) {
//         if(n == 2)
//             return 1;

//         if(n == 3)
//             return 2;

//         // rem for % 3 can be only 0, 1 or 2
//         if(n % 3 == 0)
//             return pow(3, n/3);

//         if(n % 3 == 1)
//             return pow(3, ((n - 4 ) / 3)) * 4;
        
//         //if(n % 3 == 2)
//             return pow(3, ((n - 5 ) / 3)) * 3 * 2;

//     }
// };