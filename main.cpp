#include <iostream>
#include <vector>
#include <algorithm>

int getMaxDistance(const std::vector<int>& numbers)
{
    std::vector<int> maxNums;

    for (int i = numbers.size()-1; i >= 0; i--)
        if(maxNums.empty() || numbers[i] > numbers[maxNums.back()])
            maxNums.push_back(i);
    std::reverse(maxNums.begin(), maxNums.end());

    int maxDist = 0;

    size_t i = 0;
    size_t j = 0;

    while(i < numbers.size() && j < maxNums.size()) {
        int leftNum = numbers[i];
        int rightNum = numbers[maxNums[j]];
        if(leftNum <= rightNum) {
            if(maxNums[j]-i > maxDist) {
                maxDist = maxNums[j]-i;
            }
            ++j;
        } else {
            ++i;
        }
    }
    return maxDist;
}

int main()
{
    int res = getMaxDistance({34, 8, 10, 3, 2, 80, 30, 33, 1});
    std::cout << "res = " << res << std::endl;
    return 0;
}
