// 621. Task Scheduler   ################ INCOMPLETE ##################################
// hint: task order does not matter.

/*
my algo:
count tasks
use max heap to sort tasks by frequency
at every cycle, pick task with highest frequency
maintain cooling tasks in another queue. when the task is ready, move it back to max heap


HINT: the cooling period for all tasks are same. the first scheduled task will cool down first. dont need to see all pending tasks
store cooling tasks in a queue. tasks can be pushed back into pq after the cooling period.

OR

Hint: only optimal number of slots reqd. not the order of tasks
Hint: can you count idles? answer = tasks + idles

https://leetcode.com/problems/task-scheduler/solutions/3280549/full-explanation-using-priority-queue-and-formula-based-approach
https://leetcode.com/problems/task-scheduler/solutions/104500/java-o-n-time-o-1-space-1-pass-no-sorting-solution-with-detailed-explanation

*/

struct Task {
    char task;
    int count;
    int timeFinished;
    //Task(char t, int c): task(t), count(c), timeFinished(INT_MIN){}
    // signed integer overflow: 0 - -2147483648 cannot be represented in type 'int' (solution.cpp)
    Task(char t, int c, int i): task(t), count(c), timeFinished(i){}
    bool operator<(const Task &other) const{
        return count < other.count;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
            map<char, int> count;

            
            for(int i = 0; i < tasks.size(); i++){
                count[tasks[i]]++;
                // if(find(count.begin(), count.end(), ) != count.end()){
                //     count[task[i]]++;
                // } else
                //     count[task[i]] = 1;
            }

            priority_queue<Task> ptasks;
            priority_queue<Task> coolingTasks;


            for(auto i : count){
                ptasks.push(Task(i.first, i.second, -1 * (n + 1))); // use dot operator if you're using auto!
            }

            int intervals = 0;
            for(;!ptasks.empty() || !coolingTasks.empty(); intervals++){
                // tasks from both Q's are eligible
                // DOESNT WORK. IF HIGHEST FREQUENCY TASK IN COOLING TASKS HAS NOT COOLED DOWN. PICK LOWER FREQUENCY TASK - i.e, PUT BACK THE COOLED TASKS 
                if((!coolingTasks.empty() && !ptasks.empty()) && intervals - coolingTasks.top().timeFinished > n && intervals - ptasks.top().timeFinished > n){
                    if(ptasks.top().count > coolingTasks.top().count){
                        Task t = ptasks.top();
                        ptasks.pop();
                        t.count--;
                        t.timeFinished = intervals;
                        if(t.count > 0)
                            coolingTasks.push(t);
                        cout << "picked " << t.task << endl;
                    } else{
                        Task t = coolingTasks.top();
                        coolingTasks.pop();
                        t.count--;
                        t.timeFinished = intervals;
                        if(t.count > 0)
                            coolingTasks.push(t);
                        cout << "picked " << t.task << endl;
                    }
                } else if(!coolingTasks.empty() && intervals - coolingTasks.top().timeFinished > n){
                    Task t = coolingTasks.top();
                    coolingTasks.pop();
                    t.count--;
                    t.timeFinished = intervals;
                    if(t.count > 0)
                        coolingTasks.push(t);
                    cout << "picked " << t.task << endl;
                } else if(!ptasks.empty() && intervals - ptasks.top().timeFinished > n){
                    Task t = ptasks.top();
                    ptasks.pop();
                    t.count--;
                    t.timeFinished = intervals;
                    if(t.count > 0)
                        coolingTasks.push(t);
                    cout << "picked " << t.task << endl;
                } else
                    cout << "skipped interval" << endl;
            }
            return intervals;
    }
};