/* 1406. Stone Game III
intuition: 
stone values may be negative
u cannot pick local optima, since later down the lane, u will end up with more negative  or lower value stones, especially since the opp player can choose number of stones as such.
brute force: at each turn, solve for picking 1 or 2 or 3 stones. find optimal output after solving for each combination
=> O(3 ^ n)// for each turn, pick 3 possibilities of stones and solve for the rest of the input.
notice, u are REPEATEDLY solving for an index for different combinations? the repetition is the clue.
note: the deciding factor is that alice is getting a head start
note: the stones must be taken from the beginning. the first move only have 3 choices, the base case. and the first player will choose optimally
wrong! the first move will be picked from local optima, not global optima. And, stones are taken from the beginning, but instead of choosing the first one, you choose the 3rd one.

try all combinations with dp. do not find max. pick all requested stones. then pick the max in the end.
if the sub problem returns, 3 values, the next level would have six values to return.
could not find the reccurence relation. isnt it like house robber? but with 2 optimal solutions.
say there are k stones, does adding more stones just extrapolate the result for k? does local maxima lead to global maxima? NO
ex: 1 2 9 1 1 10
if alice picks local maxima, 12(1 + 2 + 9); bob also gets 12 (1 + 1 + 10), a tie.
instead if alice picks 3(1 + 2). bob can only pick 11(9  1 + 1). alice again can pick 10. thus, leaving alice the winner.

elaborating the brute force method earlier.
let alice pick, 1 or 2 or 3 stone. follow all paths and in the end if in any combination when 0 stones left, if alice has higher score than bob, alice is the winner(she has a head start).
if the scores are same in all paths, its a tie. else bob is the winner.

https://youtu.be/HsLG5QW9CFQ
Hint: combine alice's score and Bob's score. alice optimises for A - B(increase A or decrease B). similarly for B. that way you dont return both values.

note:
877. Stone Game
1140. Stone Game II
1406. Stone Game III
1510. Stone Game IV
1563. Stone Game V
1686. Stone Game VI
1690. Stone Game VII
1872. Stone Game VIII
2029. Stone Game IX
1046. last stone weight
1049. last stone weight II
*/

// UNSOLVED!!
// brute force
// WRONG. this assumes Alice plays optimally but not bob?
class Solution {
    string answer;
public:
    Solution():answer("Bob"){}
    string Answer() {return this -> answer;}
    // return player's score. 
    // even: alice. odd : bob
    void play(vector<int>& stones, int i, int aScore, int bScore, int turn){
        if(i >= stones.size()){
            if(aScore > bScore) // alice gets higher prioirty. Alice gets a higher score in ANY ONE path.
                this -> answer = "Alice";
            else if (aScore == bScore && this -> answer == "Bob") // alice gets higher priority
                this -> answer = "Tie";
            return ; // todo: prune, once A wins
        }

        // todo: prune, if A score is 1 more than half total score, A wins.

        // pick one stone
        // todo: multiple conditional operators can be combined to calculate A score or B score only
        play(stones, i + 1, turn % 2 == 0? aScore + stones[i] :  aScore, 
                            turn % 2 == 1? bScore + stones[i] :  bScore, turn + 1);

        // pick 2 stones
        if(i + 1 < stones.size())
            play(stones, i + 2, turn % 2 == 0? aScore + stones[i] + stones[i + 1] :  aScore, 
                                turn % 2 == 1? bScore + stones[i] + stones[i + 1] :  bScore, turn + 1);

        // pick 3 stones
        if(i + 2 < stones.size())
            play(stones, i + 3, turn % 2 == 0? aScore + stones[i] + stones[i + 1] + stones[i + 2] :  aScore, 
                                turn % 2 == 1? bScore + stones[i] + stones[i + 1] + stones[i + 2] :  bScore, turn + 1);

        // wrong. u are combining alice and bob's scores
        // int score = max({x, y, z}); // each player, playing his optimal turn
        // if(turn)
        //     return aScore + score;
        // else
        //     return bScore + score;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // less than num of stones. space for max
        // a score for a given turn and no of stones and index, the scores are all different. what to cache?
        // vector<int> scores(stoneValue.size(), -1);
        // start from back of the array. in recursion/ dfs, the depth, i.e, the start gets processed first
        // int aScore = max(play(stoneValue, 0, 0, 0, 1, 1), // all stones, index, a score, b score, turn, no of stones to pick
        //                     play(stoneValue, 0, 0, 0, 1, 2),
        //                         play(stoneValue, 0, 0, 0, 1, 3));
        // int bScore = total - aScore; // bob's score is total - alice's score


        play(stoneValue, 0, 0, 0, 0);
        return this -> Answer();
    }
};

// local optima
// class Solution {
// public:
//     // return player's score. 
//     int play(vector<int>& stones, int i, int aScore, int bScore, int turn){
//         if(i < 0)
//             return 0;

//         int nxtTurn = turn == 1? 0 : 1; // 1: alice. 0 : bob

//         int x = INT_MIN, y = INT_MIN, z = INT_MIN;

//         x = play(stones, i - 1, aScore, bScore, nxtTurn) + stones[i];

//         if(i - 2 >= 0)
//             y = play(stones, i - 2, aScore, bScore, nxtTurn) + stones[i] + stones[i - 1];
//         else if( i - 1 >= 0)
//             y = stones[i] + stones[i - 1];

//         if(i - 3 >= 0)
//             z = play(stones, i - 3, aScore, bScore, nxtTurn) + stones[i] + stones[i - 1] + stones[i - 2];
//         else if (i - 2 >= 0)
//             z = stones[i] + stones[i - 1] + stones[i - 2];

//         int score = max({x, y, z}); // each player, playing his optimal turn

//         if(turn)
//             return aScore + score;
//         else
//             return bScore + score;
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int total = 0;

//         for(auto i : stoneValue)
//             total += i;

//         // start from back of the array. in recursion/ dfs, the depth, i.e, the start gets processed first
//         int aScore = play(stoneValue, stoneValue.size() - 1, 0, 0, 1);
//         int bScore = total - aScore; // bob's score is total - alice's score

//         if(aScore > bScore)
//             return "Alice";
//         else if (aScore == bScore)
//             return "Tie";
//         else
//             return "Bob";
//     }
// };