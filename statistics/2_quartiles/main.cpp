#include <iostream>
#include <vector>
#include <algorithm>

double Q2(std::vector<int> &array) {
    std::sort(array.begin(), array.end());

    return array.size() % 2 == 0 ? 
        ((double)array[array.size() / 2] + (double)array[array.size() / 2 - 1]) / 2 : array[array.size() / 2];
}

double Q1(std::vector<int> &array) {
    std::sort(array.begin(), array.end());

    if (array.size() % 2 == 0) {
        return array[array.size() / 4];
    }
    else {
        if (array.size() / 2 % 2 == 0) {
            return (array[array.size() / 4] + array[array.size() / 4 - 1]) / 2;
        }
        else {
            return array[array.size() / 4];
        }
    }
}

int Q3(std::vector<int> &array) {
    std::sort(array.begin(), array.end());

    if (array.size() % 2 == 0) {
        if (array.size() / 2 % 2 == 0) {
            return (array[array.size() * 3 / 4] + array[array.size() * 3 / 4 - 1]) / 2;
        }
        else {
            return array[array.size() / 2 + array.size() / 4];
        }
    }
    else {
        if (array.size() / 2 % 2 == 0) {
            return (array[array.size() * 3 / 4] + array[array.size() * 3 / 4 + 1]) / 2;    
        }
        else {
            return array[array.size() / 2 + array.size() / 4];
        }
    }
}

int main() {
    int inputSize = 0;
    std::cin >> inputSize;

    std::vector<int> theArray;
    for (int i = 0; i < inputSize; i++) {
        int input;
        std::cin >> input;
        theArray.push_back(input);
    }   
    
    std::cout << Q1(theArray) << std::endl;
    std::cout << Q2(theArray) << std::endl;
    std::cout << Q3(theArray) << std::endl;
    return 0;
}