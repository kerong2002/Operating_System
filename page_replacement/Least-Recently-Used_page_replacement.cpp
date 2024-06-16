#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

void lruPageReplacement(int reference_string[], int n, int capacity) {
    // To store the pages in memory
    list<int> lru_queue;

    // To store the index of pages in memory
    unordered_map<int, list<int>::iterator> page_map;

    // Start counting page faults
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        // If the page is already in memory
        if (page_map.find(reference_string[i]) != page_map.end()) {
            // Update its position in the queue (move to the front)
            lru_queue.erase(page_map[reference_string[i]]);
            lru_queue.push_front(reference_string[i]);
            page_map[reference_string[i]] = lru_queue.begin();
        }
        else {
            // If the memory is full
            if (lru_queue.size() == capacity) {
                int least_recently_used = lru_queue.back();
                lru_queue.pop_back();
                page_map.erase(least_recently_used);
            }

            // Insert the current page into memory
            lru_queue.push_front(reference_string[i]);
            page_map[reference_string[i]] = lru_queue.begin();

            // Increment page fault count
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
    int capacity = 4;

    // Call the LRU page replacement function
    lruPageReplacement(reference_string, n, capacity);

    return 0;
}
