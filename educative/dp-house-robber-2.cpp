#include <iostream>
#include <vector>

int maxRob(const vector<int> & money, int start, int end){
    int rob1, rob2;
    rob1 = money[start];
    rob2 = max(money[start], money[start + 1]);

    for(int i = start + 2; i <=end; i++) {
        int t = max(rob1 + money[i], rob2);
        rob1 = rob2;
        rob2 = t;
    }
    return rob2;
}

int HouseRobber(const std::vector<int>& money) {
    return max(maxRob(money, 1, money.size()-1), maxRob(money, 0, money.size()-2));
}