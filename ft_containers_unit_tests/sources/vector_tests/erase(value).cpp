#include "../system/system_methods.ipp"
#include "__service.ipp"

template <typename T>
std::vector<int> erase_test_1(std::vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 99000000; ++i)
        vector.push_back(i);
    g_start1 = timer();
    v.push_back(*(vector.erase(vector.begin() + 80000)));
    g_end1 = timer();
    v.push_back(*(vector.begin() + 82000));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> erase_test_1(_vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 99000000; ++i)
        vector.push_back(i);
    g_start2 = timer();
    v.push_back(*(vector.erase(vector.begin() + 80000)));
    g_end2 = timer();
    v.push_back(*(vector.begin() + 82000));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {

    run_vector_unit_test<int>("erase(value)", erase_test_1, erase_test_1);

    return (0);
}