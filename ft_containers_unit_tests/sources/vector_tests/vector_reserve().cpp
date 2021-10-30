#include "../system/lib.hpp"

template <typename T>
std::vector<int> reserve_test(std::vector<T> vector) {
    std::vector<int> v;
    g_start1 = timer();
    vector.reserve(99000000);
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> reserve_test(_vector<T> vector) {
    std::vector<int> v;
    g_start2 = timer();
    vector.reserve(99000000);
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    run_vector_unit_test<int>("reserve()", reserve_test, reserve_test);

    return (0);
}