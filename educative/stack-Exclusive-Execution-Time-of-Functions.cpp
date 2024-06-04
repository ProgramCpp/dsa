#include "Logs.cpp"
#include "Libraries.cpp"


struct FnStartTime {
    int functionId; // not necessary- each function has valid pairs of start and stop. needed to update parent function execution time
    int startTime;
    FnStartTime(int f, int s): functionId(f),startTime(s){}
};

vector<int> ExclusiveTime(int n, vector<string> logs)
{
    stack<FnStartTime> startTimes;
    vector<int> runtimes(n);
    // int childFnRunTIme = 0;

    for(int i = 0; i < logs.size(); i++){
        stringstream ss(logs[i].c_str());
        string functionId;
        getline(ss, functionId, ':');
        int iFunctionId = stoi(functionId);
        string action;
        getline(ss, action, ':');
        string timestamp;
        getline(ss, timestamp, ':');
        int iTimestamp = stoi(timestamp);

        cout<< iFunctionId << ":" << action << ":" << iTimestamp << ",";

        if (action == "start"){
            startTimes.push(FnStartTime(iFunctionId, iTimestamp));
        }else{
            FnStartTime startFn = startTimes.top();
            startTimes.pop();
            //? why + 1?
            runtimes[iFunctionId] += iTimestamp - startFn.startTime + 1;
            if(!startTimes.empty()){
                // ? how to update parent to parent execution time? all subtractions add up
                runtimes[startTimes.top().functionId] -= iTimestamp - startFn.startTime + 1;
            }
        }
    }

    return runtimes;
}