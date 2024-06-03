// 1488. Avoid Flood in The City (greedy)

/*
use priority queue to dry the most frequent lake first. because there are chances that this lake appears sooner in the list.
keep track of frequency of rains on all lakes.

*CHANCES* is a wrong idea. if two lakes have same frequency, the one to come first must be dried up

priority queue must sort based on two factors. frequency and order - not possible. the order of remaining lakes at given point keeps changing, no point in maintaining the pq then!

ABORT!

https://github.com/rootkonda/LeetCode/blob/master/1488.%20Avoid%20Flood%20in%20The%20City.cpp

you are tracking flooded lakes and figuring the lake to dry

instead, track driable days and flooded lakes. on second occasion of flooding, pick a day to dry. 
remember, you dont HAVE to dry a lake. u can skip it too. so you dont need to handle remaining driable days

*/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, int> lakesRained;
        list<int> driableDays; // FIFO but also remove from the middle. the first day after it has rained over the lake
        vector<int> driedLakes(rains.size(), -1);
        for(int i = 0; i < rains.size(); i++){
            if(rains[i] == 0){
                driableDays.push_back(i);
            } else{
                if(lakesRained.find(rains[i]) != lakesRained.end()){
                    // handled below
                    // if(driableDays.empty()){
                    //     cout << "no driable days";
                    //     return vector<int>();
                    // }
                    int d = -1;
                    // the driable day must be after it has rained over the lake
                    for(auto j = driableDays.begin(); j != driableDays.end(); j++){
                        if(*j > lakesRained[rains[i]]){
                            d = *j;
                            driableDays.erase(j);
                            break;
                        }
                    }
                    
                    if(d == -1){
                        cout << "no driable days for rain " << rains[i] << ".last rained " << lakesRained[rains[i]] << ". current day " << i << ". available day " << d;
                        return vector<int>();
                    }
                        
                    driedLakes[d] = rains[i];
                    lakesRained.erase(rains[i]);
                }
                lakesRained[rains[i]] = i ;
            }
        }

        // days when there is no need to dry any lakes. leave it 1
        for(auto j = driableDays.begin(); j != driableDays.end(); j++){
            driedLakes[*j] = 1;
        }

        return driedLakes;
    }
};


// struct lake {
//     int id;
//     int count;

//     lake(int i, int c):id(i),count(c){}

//     bool operator<(const lake &other) const{
//         return count < other.count;
//     }
// };

// class Solution {
// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         map<int, int> count;

//         for(auto rain : rains){
//             count[rain]++;
//         }

//         priority_queue<lake> mostFrequentLakes;
//         map<int, bool> hasRained;
//         vector<int> driedLakes(rains.size(), -1);
//         for(int i = 0; i < rains.size(); i++){
//             if(rains[i] == 0){
//                 if(!mostFrequentLakes.empty()){
//                     lake l = mostFrequentLakes.top();
//                     mostFrequentLakes.pop();
//                     hasRained[l.id] = false;
//                     driedLakes[i] = l.id;
//                 } else{
//                     driedLakes[i] = 1;
//                 }
//             } else{
//                 if(hasRained.find(rains[i]) != hasRained.end() && hasRained[rains[i]])
//                     return vector<int>();
//                 count[rains[i]]--;
//                 hasRained[rains[i]]= true;
//                 mostFrequentLakes.push(lake(rains[i], count[rains[i]]));
//             } 
//         }

//         return driedLakes;
//     }
// };