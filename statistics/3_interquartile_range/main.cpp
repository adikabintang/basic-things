#include <iostream>
#include <vector>
#include <algorithm>

double median(std::vector<int> &vec, int left, int right) {
    int n = right - left + 1;
    
    if (n % 2 != 0) {
        return (double)vec.at(left + (n / 2));
    }
    else {
        int x1 = vec.at(left + n / 2);
        int x2 = vec.at(left + n / 2 - 1);
        double res = ((double)x1 + (double)x2) / 2;
        return res;
    }
}

double interquartile_range(std::vector<int> &vec) {
    double result;
    auto size = vec.size();

    double q1 = median(vec, 0, size / 2 - 1);
    double q3 = median(vec, (size % 2 != 0 ? (size / 2 + 1) : size / 2), size - 1);
    return q3 - q1;
}

int main() {
    int n;
    std::vector<int> x;
    std::vector<int> f;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int in;
        std::cin >> in;
        x.push_back(in);
    }

    for (int i = 0; i < n; i++) {
        int in;
        std::cin >> in;
        f.push_back(in);
    }

    std::vector<int> final_array;
    
    // get number of all elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < f.at(i); j++) {
            final_array.push_back(x.at(i));
        }
    }

    std::sort(final_array.begin(), final_array.end());

    printf("%.1f\n", interquartile_range(final_array));
    return 0;    
}