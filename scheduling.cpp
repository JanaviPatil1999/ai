#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs by decreasing order of profit
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find maximum profit using Greedy approach
pair<int, vector<Job>> jobScheduling(vector<Job>& jobs) {
    // Sort jobs by decreasing order of profit
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    // Find the maximum deadline
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Initialize an array to keep track of time slots
    vector<bool> timeSlots(maxDeadline, false);
    
    // Initialize variables to keep track of total profit and scheduled jobs
    int totalProfit = 0;
    vector<Job> scheduledJobs;
    
    // Iterate through each job
    for (const Job& job : jobs) {
        // Find the latest available time slot before the deadline
        for (int i = min(job.deadline, maxDeadline) - 1; i >= 0; --i) {
            if (!timeSlots[i]) {
                // Schedule the job at this time slot
                timeSlots[i] = true;
                totalProfit += job.profit;
                scheduledJobs.push_back(job);
                break;
            }
        }
    }
    
    return make_pair(totalProfit, scheduledJobs);
}

int main() {
    // Example usage
    vector<Job> jobs = { {1, 9, 15}, {2, 2, 2}, {3, 5, 18}, {4, 7, 1}, {5, 4, 25}, {6, 2, 20} };
    
    pair<int, vector<Job>> result = jobScheduling(jobs);
    
    cout << "Maximum profit: " << result.first << endl;
    cout << "Scheduled jobs: ";
    for (const Job& job : result.second) {
        cout << job.id << " ";
    }
    cout << endl;
    
    return 0;
}
