#include <vector>

using namespace std;

vector<vector<int>> knapsack01 (vector<int>& values, vector<int>& weights, int c) {

    vector<vector<int>> array(values.size() + 1, vector<int>(c + 1));
    for (int j = 0; j <= c; j++) array[0][j] = 0;
    for (int i = 0; i <= values.size(); i++) array[i][0] = 0;

    for (int i = 1; i <= values.size(); i++) {
        for (int j = 1; j <= c; j++) {
            if (weights[i - 1] <= j) {
                array[i][j] = max(array[i - 1][j], array[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                array[i][j] = array[i - 1][j];
            }
        }
    }

    return array;

}