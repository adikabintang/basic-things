#include <iostream>
#include <vector>
#include <algorithm>

void printArray(std::vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

double mean(std::vector<int> &array) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i];
    }

    return (double)((double)sum / (double)array.size());
}

double median(std::vector<int> &array) {
    std::sort(array.begin(), array.end());

    return array.size() % 2 == 0 ? 
        ((double)array[array.size() / 2] + (double)array[array.size() / 2 - 1]) / 2 : array[array.size() / 2];
}

// O(n^2)
int mode(std::vector<int> &the_array) {
    int temp_counter = 0;
    int highest_counter = 0;
    int mode_index = 0;

    for (int i = 0; i < the_array.size(); i++) {
        temp_counter = 0;
        for (int j = 0; j < the_array.size(); j++) {
            if (the_array[j] == the_array[i]) {
                temp_counter++;
            }
        }

        if (temp_counter > highest_counter) {
            mode_index = i;
            highest_counter = temp_counter;
        }
    }

    return the_array[mode_index];
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
    //printArray(theArray);
    std::cout << mean(theArray) << std::endl;
    std::cout << median(theArray) << std::endl;
    std::cout << mode(theArray) << std::endl;
    return 0;
}