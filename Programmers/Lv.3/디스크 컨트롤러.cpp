#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task{
    int num;
    int inputTime;
    int duration;
    Task(int num, int inputTime, int duration)
        : num(num), inputTime(inputTime), duration(duration){}
    bool operator>(const Task& other) const {
        if (duration == other.duration){
            if (inputTime == other.inputTime){
                return num > other.num;
            } else {
                return inputTime > other.inputTime;
            }
        } else {
            return duration > other.duration;
        }
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<Task, vector<Task>, greater<Task>> pq;
    int time = 0;
    int idx = 0;
    int answer = 0;
    Task* curTask = nullptr;
    
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    
    do {
        while (idx < jobs.size() && jobs[idx][0] <= time){
            pq.push(Task(idx, jobs[idx][0], jobs[idx][1]));
            ++idx;
        }
        
        if (curTask != nullptr){
            --(curTask->duration);
            if (curTask->duration == 0){
                answer += time - curTask->inputTime;
                delete curTask;
                curTask = nullptr;
            }
        }
        
        if (curTask == nullptr && !pq.empty()){
            Task cur = pq.top();
            pq.pop();
            curTask = new Task(cur.num, cur.inputTime, cur.duration);
        }
        
        ++time;
    } while (idx < jobs.size() || !pq.empty() || curTask != nullptr);
    return answer / jobs.size();
}