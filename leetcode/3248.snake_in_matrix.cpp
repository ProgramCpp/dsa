/*
3248. Snake in Matrix
two indices i and j to track the snake. after processing all the commands, compute the cell id.
*/
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
    int i = 0, j = 0;

        for(auto command : commands){
            if(command == "RIGHT")
                j++;
            if(command == "LEFT")
                j--;
            if(command == "UP")
                i--;
            if(command =="DOWN")
                i++;
        }

        return (i * n ) + j;
    }
};