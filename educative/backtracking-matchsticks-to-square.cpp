bool CheckSquare(vector<int> matchsticks, int perimeter, int s1, int s2, int s3, int s4, int i){
    if (s1 + s2 + s3 + s4 == perimeter && i == matchsticks.size())
        return true;
        
    bool done = false;
    if (s1 + matchsticks[i] <= perimeter / 4)
        done = CheckSquare(matchsticks, perimeter, s1+ matchsticks[i], s2, s3, s4, i + 1);
    if (done)
        return done;
    if (s2 + matchsticks[i] <= perimeter / 4)
        done = CheckSquare(matchsticks, perimeter, s1, s2 + matchsticks[i], s3, s4, i + 1);
    if (done)
        return done;
    if (s3 + matchsticks[i] <= perimeter / 4)
        done = CheckSquare(matchsticks, perimeter, s1, s2, s3 + matchsticks[i], s4, i + 1);
    if (done)
        return done;
    if (s4 + matchsticks[i] <= perimeter / 4)
        done = CheckSquare(matchsticks, perimeter, s1, s2, s3, s4 + matchsticks[i], i + 1);
        
    return done;

}

bool MatchstickToSquare(vector<int> matchsticks)
{
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (perimeter % 4)
        return false;
    return CheckSquare(matchsticks, perimeter, 0,0,0,0,0);
}