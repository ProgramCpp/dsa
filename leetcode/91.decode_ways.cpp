/* 91. Decode Ways
intuition: 
possible values: 1 - 9 & 1{0-9} & 2{0-6}
at any given index, there are two possibilities, 1 digit or two digits. two digitis are valid only if the first digit is 1 or 2.
consider one digit and then solve for the rest of the solution. then repeat for 2 digits.
cache the solutions for sub problems.
res<n>  = res<n+1> + res<n+2> 
*/


// accepted
class Solution {
public:

    int decode(string s, int n, vector<int> &noOfWays){
        int k = s.size();
        if(noOfWays[n - k] != -1)
            return noOfWays[n-k];

        if(k == 0)
            return 0;

        // 1st letter cannot be 0
        if(s[0] == '0')
            return -1;

        int n1 = 0;
        if(k == 1)
            n1 = 1;
        else if(k > 1){ // OOB without index checks
            int x = decode(s.substr(1), n, noOfWays); // except the 1st char at 0th index
            if (x != -1)
                n1 = x;
        }

        int n2 = 0;
        if(k >= 2){ // 2 length digits possible
            if (s[0] == '1' || (s[0] == '2' && (s[1] >= '0' && s[1] <= '6'))) {
                if(k == 2)
                    n2 = 1;
                 else if ( k > 2){
                    int x = decode(s.substr(2), n, noOfWays);
                    if (x != -1)
                        n2 = x;
                }
            }
        }

        noOfWays[n-k] = n1 + n2; // HINT: compute n1 and n2 separately. do not overwrite

        return noOfWays[n-k];
    }

    int numDecodings(string s) {
        vector<int> noOfWays(s.size(), -1); // **TODO** optimize: differentiate uncalculated value and invalid possibilities

        int x = decode(s, s.size(), noOfWays);
        if (x == -1)
            return 0;

        return x;
    }
};