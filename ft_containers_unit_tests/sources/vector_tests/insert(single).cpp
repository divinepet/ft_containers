#include "../system/lib.hpp"

template <typename T>
std::vector<int> insert_test_1(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(26000000, 1);
    g_start1 = timer();
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_1(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(26000000, 1);
    g_start2 = timer();
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    run_vector_unit_test<int>("insert(signle)", insert_test_1, insert_test_1);

    return (0);
}