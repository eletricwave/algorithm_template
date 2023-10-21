#include <iostream>
#include <vector>

using namespace std;

vector<int> slove(int n, vector<vector<int>> query){
    vector<int> diff(n, 0);

    for (const auto &x : query){
        diff[x[0]] += x[2];
        if (x[1] + 1 < n)
            diff[x[1] + 1] -= x[2];
    }
    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];
    return ans;
}

int main(void){


    return 0;
}