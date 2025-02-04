#include <vector>

using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    const int start = 0;
    const int end = 1;

    merge_sort_intervals(intervals, 0, intervals.size() - 1);

    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i][end] >= intervals[i + 1][start]) {
            intervals[i][end] = max(intervals[i][end], intervals[i + 1][end]);
            intervals.erase(intervals.begin() + i + 1);
            i--;
        }
    }

    return intervals;
}

int merge (vector<vector<int>>& intervals, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> left_array(n1, vector<int>(2));
    vector<vector<int>> right_array(n2, vector<int>(2));

    for (int i = 0; i < n1; i++) {
        left_array[i] = intervals[left + i];
    }

    for (int i = 0; i < n2; i++) {
        right_array[i] = intervals[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    const int start = 0;
    while (i<n1 && j<n2) {
        if (left_array[i][start] <= right_array[j][start]) {
            intervals[k] = left_array[i];
            i++;
        } else {
            intervals[k] = right_array[j];
            j++;
        }
        k++;
    }   

    while (i<n1) {
        intervals[k] = left_array[i];
        i++;
        k++;
    }

    while (j<n2) {
        intervals[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort_intervals (vector<vector<int>>& array, int left, int right) {
    
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_intervals(array, left, mid);
    merge_sort_intervals(array, mid + 1, right);
    merge(array, left, mid, right);
}
