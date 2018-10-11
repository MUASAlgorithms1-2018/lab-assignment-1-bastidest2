#include <iostream>
#include <vector>
#include <list>
#include <cassert>

int cubic_mss(const std::vector<int>& elements) {
    int currentMax = 0;
    for(int i = 0; i < elements.size(); i++) {
        for(int j = i; j < elements.size(); j++) {
            int currentSum = 0;
            for(int a = i; a <= j; a++) {
                currentSum += elements[a];
            }
            if(currentSum > currentMax) {
                currentMax = currentSum;
            }
        }
    }
    return currentMax;
}

int quadratic_mss(const std::vector<int>& elements) {
    int currentMax = 0;
    for(int i = 0; i < elements.size(); i++) {
        int currentSum = 0;
        for(int j = i; j < elements.size(); j++) {
            currentSum += elements[j];
            if(currentSum > currentMax) {
                currentMax = currentSum;
            }
        }
    }
    return currentMax;
}

int linear_mss(const std::vector<int>& elements) {
    int maxSum = 0;
    int thisSum = 0;
    for(int i = 0; i < elements.size(); i++) {
        thisSum += elements[i];
        if(thisSum > maxSum) {
            maxSum = thisSum;
        } else if(thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

int main() {
    static const std::list<std::pair<std::vector<int>, int>> inputs {
        {{1, 2, -30, 4, 5}, 9},
        {{1, 2, -35, 4, 5}, 9},
        {{1, 2, -30, 4, 99}, 103},
        {{5, 5, -30, 4, 5}, 10},
        {{1, 2, 30, 4, 5}, 42},
        {{1, 2, -1, 4, 5}, 11}
    };

    for(const auto& input : inputs) {
        std::cout << "Test" << ": expect " << input.second << "...";
        assert(cubic_mss(input.first) == input.second);
        assert(quadratic_mss(input.first) == input.second);
        assert(linear_mss(input.first) == input.second);
        std::cout << "OK" << std::endl;
    } 
    return 0;
}
