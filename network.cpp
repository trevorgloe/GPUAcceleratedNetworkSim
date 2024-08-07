// This is an initial script to create a model for networks

#include <iostream>
#include <vector>
#include <stdio.h>

void print_float_vec(std::vector<float>& vec);

int main() {
    std::vector<float> t;
    t.reserve(100);
    float max = 10;

    for (int n=0; n < 100; n++) {
        t.push_back((n / 100) *  max);
    }

    print_float_vec(t);
}

void print_float_vec(std::vector<float>& vec) {
    std::cout << vec[0];
    printf("Vector is size %d", (int) vec.size());
    for (float val : vec) {
        std::cout << val << ' ';
    }
}