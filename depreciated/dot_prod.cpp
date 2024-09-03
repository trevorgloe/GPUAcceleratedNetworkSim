// Function to test python bindings for C++

float dot(std::vec<float> v1, std::vec<float> v2) {
    int size1 = v1.size();
    int size2 = v2.size();

    std::vec<float> out;
    out.reserve(size1);
    float tot = 0;

    for (int n=0; n < size1; n++) {
        tot = tot + v1[n] * v2[n];
    }

    return tot;
}