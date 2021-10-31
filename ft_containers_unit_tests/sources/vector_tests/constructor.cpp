#include "../system/lib.hpp"

template <typename T>
std::vector<int> constructor_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp(4, 4), tmp2(5, 5);
    tmp = tmp;
    tmp = tmp2;
    std::vector<int> tmp3(tmp);
    std::vector<int> tmp4(tmp.begin(), tmp.end());
    v.push_back(tmp4.size());
    v.push_back(tmp4.capacity());
    v.push_back(tmp[2]);
    v.push_back(tmp3[2]);
    v.push_back(tmp4[2]);
    try { std::vector<int> tmp5(-1, -1); }
    catch (std::exception &e) { v.push_back(1); }
    g_start1 = timer();
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> constructor_test(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp(4, 4), tmp2(5, 5);
    tmp = tmp;
    tmp = tmp2;
    _vector<int> tmp3(tmp);
    _vector<int> tmp4(tmp.begin(), tmp.end());
    v.push_back(tmp4.size());
    v.push_back(tmp4.capacity());
    v.push_back(tmp[2]);
    v.push_back(tmp3[2]);
    v.push_back(tmp4[2]);
    try { _vector<int> tmp5(-1, -1); }
    catch (std::exception &e) { v.push_back(1); }
    g_start2 = timer();
    g_end2 = timer();
    return v;
}

int main() {

    run_vector_unit_test<int>("constructor", constructor_test, constructor_test);

    return (0);
}