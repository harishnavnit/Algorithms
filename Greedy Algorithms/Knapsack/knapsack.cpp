#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> weight, value, res;
    int weight, amt;

    for(int i = 0; i < value.size(); i++) {
        // Sort in descending order
        sort(value.end, value.start);

        while(weight > 0) {
            amt  = min(weight, weight[i]);
            res[i] = amt;
            weight = weight - amt;
            i++;
        }
    }
    return 0;
}
