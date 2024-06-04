#include <iostream>
#include <vector>

int RescueBoats(vector<int> people, int limit)
{
    sort(people.begin(), people.end());

    int boats = 0;
    for(int start = 0, end= people.size()-1; start <= end;){
        if (people[start] + people[end] <= limit){
            start++;
            end--;
        } else
            end--;
        boats++;
    }

    return boats;
}