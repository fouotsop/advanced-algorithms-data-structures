#include <vector>

using namespace std;

int maxSubArray(vector<int> list) {

    int sum = list[0];
    int max = list[0]; 

    int i = 1;

    while (i<list.size()) {
        if (sum < 0) {
            sum = list[i];
        } else {
            sum += list[i];
        }

        if (sum > max) {
            max = sum;
        }
        i++;
    }
}