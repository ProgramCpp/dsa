/* 621. Task Scheduler
frequent tasks must be picked on priority since they will be left in te end and each task leaves the cpu idle 
count the frequency of tasks and sort in asc.
perform a task and push it onto a queue with the time it can be processed again and the remaining frequency.
process tasks from input and queue
alternatively, do not process tasks from cooling task queue. when tasks cool down, move it back to pending task list.
*/

// 56/72
struct task {
    char t;
    int freq;
    int time;
    task():t('0'),freq(0),time(0){}
    task(char c, int f): t(c), freq(f), time(0){}
    task(char c, int f, int t): t(c), freq(f), time(t){}
    bool operator< (task const &other) const { // order pending tasks in pq
        return freq < other.freq;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;

        for(auto t : tasks){
            freq[t]++;
        }

        priority_queue<task> penTasks;

        for(auto t : freq){
            penTasks.push(task(t.first, t.second));
        }

        queue<task> coolTasks;
        int currentTime = 0;

        while(!penTasks.empty() || !coolTasks.empty()){
            task t;
            // NOTE: ** 4 combinations of state of coolTasks and pending tasks **
            // pick pt or ct, only pt empty, only ct empty, both pt and ct empty
            // when both are not empty and tasks have cooled down, pick one with higher frequency
            if(!penTasks.empty() && !coolTasks.empty()){
                if(coolTasks.front().time <= currentTime){
                    if (coolTasks.front().freq >= penTasks.top().freq){
                        t = coolTasks.front();
                        coolTasks.pop();
                    } else {
                        t = penTasks.top();
                        penTasks.pop();
                    }
                } else {
                    t = penTasks.top();
                    penTasks.pop();
                }
            } else if (!penTasks.empty()){
                t = penTasks.top();
                penTasks.pop();
                // cout << "pen task " << t.t<< endl;
            }else if (!coolTasks.empty()) {// no pending tasks. move current time to pick cooling tasks
                // cout << "idle time " << endl;
                t = coolTasks.front();
                coolTasks.pop();
                if (t.time > currentTime)// when the higher frequency pending tasks are processed, the ccooling tasks would have cooled long in past
                    currentTime = t.time;
            }else{
                // cout <<"no tasks" << endl;
                break; // no pending task or cooling task
            }

            currentTime++;// task processed
            t.freq--;
            // cout << "process task " << t.t << " " << t.freq << endl;
            cout << currentTime << " ";
            if(t.freq > 0){
                
                // -1, current time already inc
                // +1, job can be picked AFTER idle time
                t.time = currentTime - 1 + n + 1; // n idle times from now
                // cout <<"pushed cool task " << t.t << " " << t.freq << " " << t.time << " " << currentTime << endl;
                coolTasks.push(t);
            }
        }

        return currentTime; // time is set to next slot after processing the tasks, counting from 0
    }
};