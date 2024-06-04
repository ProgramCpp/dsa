#include <iostream>
#include <unordered_map>
#include <vector>

class RequestLogger {
    private:
        std::unordered_map<std::string, int> requests;
        int timeLimit;

    public:

    RequestLogger(int newTimeLimit):timeLimit(newTimeLimit){
        
    }
    
    bool MessageRequestDecision(int timestamp, std::string request) {
        cout << timeLimit << endl;
        if(requests.find(request) == requests.end()){
            cout << request << " not found" << endl;
            requests[request] = timestamp;
            return true;
        }
        cout << request << " :" << requests[request] << endl;
        bool result = timestamp - requests[request] >= timeLimit;
        if(result) // update timestamp only if request is allowed
            requests[request] = timestamp;
        return result;
    }
};
