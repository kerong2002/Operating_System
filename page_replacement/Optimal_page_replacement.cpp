#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void optimalPageReplacement(int reference_string[], int n, int capacity) {
    // To store the pages in memory
    unordered_set<int> s;

    // To store the future indices of pages
    unordered_map<int, int> future_indices;

    // Start counting page faults
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        // If the page is not already in memory
        if (s.find(reference_string[i]) == s.end()) {
            // If the memory is full
            if (s.size() == capacity) {
                int farthest = i, val = -1;

                // Find the page that will not be used for the longest period of time
                for (auto it = s.begin(); it != s.end(); it++) {
                    int j;
                    for (j = i + 1; j < n; j++) {
                        if (reference_string[j] == *it) {
                            if (j > farthest) {
                                farthest = j;
                                val = *it;
                            }
                            break;
                        }
                    }
                    // If the page is not found in the future, it can be replaced
                    if (j == n) {
                        val = *it;
                        break;
                    }
                }

                // Remove the page found in the above loop
                s.erase(val);
            }

            // Insert the current page into the set
            s.insert(reference_string[i]);

            // Increment the number of page faults
            page_faults++;
        }

        // Update the future indices map
        future_indices[reference_string[i]] = i;
    }

    // Output the total number of page faults
    cout << "Total page faults: " << page_faults << endl;
}

int main() {
    // Example reference string and capacity
    int reference_string[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    int capacity = 4;

    // Call the Optimal page replacement function
    optimalPageReplacement(reference_string, n, capacity);

    return 0;
}
