#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class SlidingWindowMedian {
    priority_queue<int> maxHeap; // Left half (max heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (min heap)
    unordered_map<int, int> hashMap; // To keep track of outdated elements

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);

            if (i >= k - 1) { // Window is full
                result.push_back(getMedian());

                // Remove the element that goes out of window
                remove(nums[i - k + 1]);
            }
        }
        return result;
    }

private:
    void insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        balanceHeaps();
    }

    void remove(int num) {
        hashMap[num]++; // Mark as outdated

        // Remove invalid elements from heaps
        if (num <= maxHeap.top()) {
            balanceHeap(maxHeap);
        } else {
            balanceHeap(minHeap);
        }

        balanceHeaps();
    }

    void balanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    void balanceHeap(priority_queue<int>& heap) {
        while (!heap.empty() && hashMap[heap.top()]) {
            hashMap[heap.top()]--;
            heap.pop();
        }
    }

    void balanceHeap(priority_queue<int, vector<int>, greater<int>>& heap) {
        while (!heap.empty() && hashMap[heap.top()]) {
            hashMap[heap.top()]--;
            heap.pop();
        }
    }

    double getMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return   minHeap.top();
    }
};

// Driver function
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SlidingWindowMedian swm;
    vector<double> result = swm.medianSlidingWindow(arr, k);

    for (double median : result) {
        cout << median << " ";
    }
    return 0;
}

