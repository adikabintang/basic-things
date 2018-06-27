/*
Standard deviation is a measure of how spread out numbers are.
Simple explanation: https://www.mathsisfun.com/data/standard-deviation.html
*/
#include <iostream>
#include <vector>
#include <cmath>

double mean(std::vector<int> &array) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i];
    }

    return (double)((double)sum / (double)array.size());
}

double stdDeviation(std::vector<int> &theArray) {
    double sum = 0;
    double meanValue = mean(theArray);

    for (int i = 0; i < theArray.size(); i++) {
        sum += pow((double)theArray[i] - meanValue, (double)2);
    }

    return pow(sum / (double)theArray.size(), 0.5);
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
    std::cout << stdDeviation(theArray);
    return 0;
}