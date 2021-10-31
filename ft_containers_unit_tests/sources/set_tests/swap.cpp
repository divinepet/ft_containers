#include "../system/lib.hpp"

template <class T>
std::vector<int> swap_test(std::set<T> st) {
    std::vector<int> v;
    g_start1 = g_end1 = timer();
    for (int i = 0; i < 250000; ++i)
        st.insert(i);
    std::set<T> st2;
    for (int i = 250000; i < 350000; ++i)
        st.insert(i);
    st.swap(st2);
    v.push_back(st2.size());
    typename std::set<T>::iterator it = st2.begin();
    for (; it != st2.end(); ++it) {
        v.push_back(*it);
    }
    std::swap(st, st2);
    typename std::set<T>::iterator it2 = st2.begin();
    for (; it2 != st2.end(); ++it2) {
        v.push_back(*it2);
    }
	return v;
}

template <class T>
std::vector<int> swap_test(_set<T> st) {
    std::vector<int> v;
    g_start2 = g_end2 = timer();
    for (int i = 0; i < 250000; ++i)
        st.insert(i);
    _set<T> st2;
    for (int i = 250000; i < 350000; ++i)
        st.insert(i);
    st.swap(st2);
    v.push_back(st2.size());
    typename _set<T>::iterator it = st2.begin();
    for (; it != st2.end(); ++it) {
        v.push_back(*it);
    }
    std::swap(st, st2);
    typename _set<T>::iterator it2 = st2.begin();
    for (; it2 != st2.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}

int main() {

    run_set_unit_test<int>("swap()", swap_test, swap_test);

    return (0);
}