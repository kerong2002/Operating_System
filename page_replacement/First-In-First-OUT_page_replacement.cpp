#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void fifoPageReplacement(int reference_string[], int n, int capacity) {
    // To store the pages in memory
    unordered_set<int> s;

    // To store the order of pages for FIFO
    queue<int> indexes;

    // Start counting page faults
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        // If the page is not already in memory
        if (s.find(reference_string[i]) == s.end()) {
            // If the memory is full
            if (s.size() == capacity) {
                // Remove the first page from the queue
                int val = indexes.front();
                indexes.pop();

                // Remove the first page from the set
                s.erase(val);
            }

            // Insert the current page into the set
            s.insert(reference_string[i]);

            // Push the current page into the queue
            indexes.push(reference_string[i]);

            // Increment the number of page faults
            page_faults++;
        }
    }

    // Output the total number of page faults
    cout << "Total page faults: " << page_faults << endl;
}

int main() {
    // Example reference string and capacity
    int reference_string[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    int capacity = 3;

    // Call the FIFO page replacement function
    fifoPageReplacement(reference_string, n, capacity);

    return 0;
}
