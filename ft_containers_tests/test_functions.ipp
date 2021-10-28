#pragma once
//#include "unit_tests.hpp"

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(_map<T, V, C> &mp) {
	mp.insert(_make_pair(16, 3));
	mp.insert(_make_pair(8, 3));
	mp.insert(_make_pair(23, 3));
	mp.insert(_make_pair(7, 3));
	mp.insert(_make_pair(19, 3));
	mp.insert(_make_pair(29, 3));
	mp.insert(_make_pair(41, 3));
	mp.insert(_make_pair(4, 3));
	mp.insert(_make_pair(11, 3));
}

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


template <typename T>
std::vector<int> push_back_test(std::vector<T> vector) {
	std::vector<int> v;
	g_start1 = timer();
	for (int i = 0; i < 55000000; ++i)
		vector.push_back(i);
	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> push_back_test(_vector<T> vector) {
	std::vector<int> v;
	g_start2 = timer();
	for (int i = 0; i < 55000000; ++i) {
		vector.push_back(i);
	}
	g_end2 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> at_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start1 = timer();
	v.push_back(vector.at(354000));
	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> at_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start2 = timer();
	v.push_back(vector.at(354000));
	g_end2 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp, tmp2;
	vector.assign(3, 3);
	tmp.assign(40000000, 1);
	tmp2.assign(4000, 1);
	g_start1 = timer();
	vector.assign(tmp.begin(), tmp.end());
	v.push_back(vector[1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.assign(tmp2.begin(), tmp2.end());
	g_end1 = timer();
	v.push_back(vector[444]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> assign_test(_vector<T> vector) {
	std::vector<int> v;
	_vector<int> tmp, tmp2;
	vector.assign(3, 3);
	tmp.assign(40000000, 1);
	tmp2.assign(4000, 1);
	g_start2 = timer();
	vector.assign(tmp.begin(), tmp.end());
	v.push_back(vector[1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.assign(tmp2.begin(), tmp2.end());
	g_end2 = timer();
	v.push_back(vector[444]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> operator1_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start1 = timer();
	v.push_back(vector[5555]);
	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> operator1_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start2 = timer();
	v.push_back(vector[5555]);
	g_end2 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> front_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start1 = timer();
	v.push_back(vector.front());
	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> front_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start2 = timer();
	v.push_back(vector.front());
	g_end2 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> back_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start1 = timer();
	v.push_back(vector.back());
	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> back_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(44444, 1);
	g_start2 = timer();
	v.push_back(vector.back());
	g_end2 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

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

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(22000000, 1);
	g_start1 = timer();
	vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
	g_end1 = timer();
	v.push_back(vector[3]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_test_2(_vector<T> vector) {
	std::vector<int> v;
	_vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(22000000, 1);
	g_start2 = timer();
	vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
	g_end2 = timer();
	v.push_back(vector[3]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(42000000, 1);
	g_start1 = timer();
	vector.insert(vector.end() - 10000000, tmp.begin(), tmp.end());
	g_end1 = timer();
	v.push_back(vector[3]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_test_3(_vector<T> vector) {
	std::vector<int> v;
	_vector<int> tmp;
	tmp.assign(26000000, 1);
	vector.assign(42000000, 1);
	g_start2 = timer();
	vector.insert(vector.end() - 10000000, tmp.begin(), tmp.end());
	g_end2 = timer();
	v.push_back(vector[3]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

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

template <typename T>
std::vector<int> erase_test_2(std::vector<T> vector) {
	std::vector<int> v;
	for (int i = 0; i < 99000000; ++i)
		vector.push_back(i);
	g_start1 = timer();
	v.push_back(*(vector.erase(vector.begin() + 80000, vector.end() - 15000000)));
	g_end1 = timer();
	v.push_back(*(vector.begin() + 82000));
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> erase_test_2(_vector<T> vector) {
	std::vector<int> v;
	for (int i = 0; i < 99000000; ++i)
		vector.push_back(i);
	g_start2 = timer();
	v.push_back(*(vector.erase(vector.begin() + 80000, vector.end() - 15000000)));
	g_end2 = timer();
	v.push_back(*(vector.begin() + 82000));
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> data_test(std::vector<T> vector) {
	std::vector<int> v;
	std::ostringstream oss;
	g_start1 = timer();
	oss << &*(vector.data());
	g_end1 = timer();
	string str = oss.str();
	if (!oss.str().rfind("0x", 0))
		v.push_back(1);
	return v;
}

template <typename T>
std::vector<int> data_test(_vector<T> vector) {
	std::vector<int> v;
	std::ostringstream oss;
	g_start2 = timer();
	oss << &*(vector.data());
	g_end2 = timer();
	string str = oss.str();
	if (!oss.str().rfind("0x", 0))
		v.push_back(1);
	return v;
}

template <typename T>
std::vector<int> begin_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start1 = timer();
	v.push_back(*vector.begin());
	v.push_back(*++vector.begin());
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> begin_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	v.push_back(*vector.begin());
	v.push_back(*++vector.begin());
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> end_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start1 = timer();
	v.push_back(*(vector.end() - 1));
	v.push_back(*(vector.end() - 2));
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> end_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	v.push_back(*(vector.end() - 1));
	v.push_back(*(vector.end() - 2));
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> rbegin_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start1 = timer();
	v.push_back(*vector.rbegin());
	v.push_back(*(vector.rbegin() + 1));
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> rbegin_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	v.push_back(*vector.rbegin());
	v.push_back(*(vector.rbegin() + 1));
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> rend_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start1 = timer();
	v.push_back(*(vector.rend() - 1));
	v.push_back(*(vector.rend() - 2));
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> rend_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	v.push_back(*(vector.rend() - 1));
	v.push_back(*(vector.rend() - 2));
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> empty_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start1 = timer();
	v.push_back(vector.empty());
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> empty_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	g_start2 = timer();
	v.push_back(vector.empty());
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> size_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(12000000, 1);
	g_start1 = timer();
	v.push_back(vector.size());
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> size_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(12000000, 1);
	g_start2 = timer();
	v.push_back(vector.size());
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> capacity_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(12000000, 1);
	g_start1 = timer();
	v.push_back(vector.capacity());
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> capacity_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(12000000, 1);
	g_start2 = timer();
	v.push_back(vector.capacity());
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> maxsize_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1, 1);
	g_start1 = timer();
	v.push_back(vector.max_size());
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> maxsize_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(1, 1);
	g_start2 = timer();
	v.push_back(vector.max_size());
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> pop_back_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start1 = timer();
	vector.pop_back();
	g_end1 = timer();
	v.push_back(vector[vector.size() - 1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> pop_back_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start2 = timer();
	vector.pop_back();
	g_end2 = timer();
	v.push_back(vector[vector.size() - 1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start1 = timer();
	vector.resize(50000000);
	vector.reserve(50000000);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(70000000);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(153000000, T());
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	v.push_back(vector[65]);
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> resize_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(99000000, 1);
	g_start2 = timer();
	vector.resize(50000000);
	vector.reserve(50000000);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(70000000);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(153000000, T());
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	v.push_back(vector[65]);
	g_end2 = timer();
	return v;
}

template <typename T>
std::vector<int> swap_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(11000000, 11);
	std::vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
	g_start1 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp3);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp2);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp4);
	g_end1 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> swap_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(11000000, 11);
	_vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
	g_start2 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp3);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp2);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp4);
	g_end2 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> clear_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(50000000, 1);
	g_start1 = timer();
	vector.clear();
	g_end1 = timer();
	v.push_back(vector.capacity());
	v.push_back(vector.size());
	return v;
}

template <typename T>
std::vector<int> clear_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(50000000, 1);
	g_start2 = timer();
	vector.clear();
	g_end2 = timer();
	v.push_back(vector.capacity());
	v.push_back(vector.size());
	return v;
}

template <typename T>
std::vector<int> iterator_test(std::vector<T> vector) {
	typename std::vector<T>::iterator it;
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		vector.push_back(i);
	it = vector.begin();
	g_start1 = timer();
	v.push_back(*(++it));
	v.push_back(*(--it));
	v.push_back(*(it + 1));
	it += 1;
	v.push_back(*(it - 1));
	it -= 1;
	v.push_back(*it);
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> iterator_test(_vector<T> vector) {
	typename _vector<T>::iterator it;
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		vector.push_back(i);
	it = vector.begin();
	g_start2 = timer();
	v.push_back(*(++it));
	v.push_back(*(--it));
	v.push_back(*(it + 1));
	it += 1;
	v.push_back(*(it - 1));
	it -= 1;
	v.push_back(*it);
	g_end2 = timer();
	return v;
}

bool operator_equal_test() {
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;	_vector<int> V_int1, V_int2, V_int3;
	std::vector<string> v_str1, v_str2;			_vector<string> V_str1, V_str2;
	v_int1.push_back(1);						V_int1.push_back(1);
	v_int3.push_back(1);						V_int3.push_back(1);
	v_str1.push_back("aa");						V_str1.push_back("aa");
	v_str2.push_back("ab");						V_str2.push_back("ab");
	result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
	v_int2.push_back(2);						V_int2.push_back(2);
	result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
	result.push_back(v_int1 == v_int3);			result_2.push_back(V_int1 == V_int3);
	result.push_back(v_str1 == v_str2);			result_2.push_back(V_str1 == V_str2);
	return result == result_2;
}

bool operator_not_equal_test() {
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<string> v_str1, v_str2;
	_vector<int> V_int1, V_int2, V_int3;
	_vector<string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 != v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 != v_int2);
	result.push_back(v_int1 != v_int3);
	result.push_back(v_str1 != v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 != V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 != V_int2);
	result_2.push_back(V_int1 != V_int3);
	result_2.push_back(V_str1 != V_str2);
	return result == result_2;
}

bool operator_more_equal_test() {
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<string> v_str1, v_str2;
	_vector<int> V_int1, V_int2, V_int3;
	_vector<string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 >= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 >= v_int2);
	result.push_back(v_int1 >= v_int3);
	result.push_back(v_str1 >= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 >= V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 >= V_int2);
	result_2.push_back(V_int1 >= V_int3);
	result_2.push_back(V_str1 >= V_str2);
	return result == result_2;
}

bool operator_less_equal_test() {
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<string> v_str1, v_str2;
	_vector<int> V_int1, V_int2, V_int3;
	_vector<string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 <= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 <= v_int2);
	result.push_back(v_int1 <= v_int3);
	result.push_back(v_str1 <= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 <= V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 <= V_int2);
	result_2.push_back(V_int1 <= V_int3);
	result_2.push_back(V_str1 <= V_str2);
	return result == result_2;
}

bool operator_more_test() {
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<string> v_str1, v_str2;
	_vector<int> V_int1, V_int2, V_int3;
	_vector<string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 > v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 > v_int2);
	result.push_back(v_int1 > v_int3);
	result.push_back(v_str1 > v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 > V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 > V_int2);
	result_2.push_back(V_int1 > V_int3);
	result_2.push_back(V_str1 > V_str2);
	return result == result_2;
}

bool operator_less_test() {
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<string> v_str1, v_str2;
	_vector<int> V_int1, V_int2, V_int3;
	_vector<string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 < v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 < v_int2);
	result.push_back(v_int1 < v_int3);
	result.push_back(v_str1 < v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 < V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 < V_int2);
	result_2.push_back(V_int1 < V_int3);
	result_2.push_back(V_str1 < V_str2);
	return result == result_2;
}

template <class T, class V>
std::vector<int> insert_test(std::map<T, V> mp) {
	std::vector<int> v;
	std::pair<std::map<int, int>::iterator , bool> pair = mp.insert(std::make_pair(7, 7));
	std::map<int, int>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second);
	mp.insert(std::make_pair(9, 9));
	std::pair<std::map<int, int>::iterator , bool> pair2 = mp.insert(std::make_pair(9, 9));
	std::map<int, int>::iterator it2 = pair.first;
	v.push_back(it2->first);
	v.push_back(it2->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second);
	g_start1 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp.insert(std::make_pair(i, j));
	}
	g_end1 = timer();
	typename std::map<T, V>::iterator it3 = mp.begin();
	for (; it3 != mp.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> insert_test(_map<T, V> mp) {
	std::vector<int> v;
	_pair<_map<int, int>::iterator , bool> pair = mp.insert(_make_pair(7, 7));
	_map<int, int>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second);
	mp.insert(_make_pair(9, 9));
	_pair<_map<int, int>::iterator , bool> pair2 = mp.insert(_make_pair(9, 9));
	_map<int, int>::iterator it2 = pair.first;
	v.push_back(it2->first);
	v.push_back(it2->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second);
	g_start2 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp.insert(_make_pair(i, j));
	}
	g_end2 = timer();
	typename _map<T, V>::iterator it3 = mp.begin();
	for (; it3 != mp.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> insert_test_2(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<int, int> mp2;
	g_start1 = timer();
	mp2.insert(mp.begin(), mp.end());
	g_end1 = timer();
	typename std::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> insert_test_2(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	_map<int, int> mp2;
	g_start2 = timer();
	mp2.insert(mp.begin(), mp.end());
	g_end2 = timer();
	typename _map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> insert_test_3(std::map<T, V> mp) {
	std::vector<int> v;
	typename std::map<T, V>::iterator it = mp.end();
	g_start1 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp.insert(it, std::make_pair(i, j));
	}
	g_end1 = timer();
	typename std::map<T, V>::iterator it2 = mp.begin();
	for (; it2 != mp.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> insert_test_3(_map<T, V> mp) {
	std::vector<int> v;
	typename _map<T, V>::iterator it = mp.end();
	g_start2 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp.insert(it, _make_pair(i, j));
	}
	g_end2 = timer();
	typename _map<T, V>::iterator it2 = mp.begin();
	for (; it2 != mp.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> at_test(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 700000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	g_start1 = timer();
	try {
		v.push_back(mp.at(400000));
		v.push_back(mp.at(400001));
	} catch (std::exception &e) {
		v.push_back(1);
	}
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> at_test(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 700000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	g_start2 = timer();
	try {
		v.push_back(mp.at(400000));
		v.push_back(mp.at(400001));
	} catch (std::exception &e) {
		v.push_back(1);
	}
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int>    iterators_test(std::map<T, V> mp) {
	std::vector<int> v;
	std::map<T, V> mpp;
	fillMap(mpp);
	for (typename std::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
	std::map<int, int> mp0;
	std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	typename std::map<T, V>::iterator it2 = mp.end();
	g_start1 = timer();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> iterators_test(_map<T, V> mp) {
	std::vector<int> v;
	_map<T, V> mpp;
	fillMap(mpp);
	for (typename _map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
	_map<int, int> mp0;
	_map<int, int>::iterator ii = mp0.insert(_make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(_make_pair(i, j));
	typename _map<T, V>::iterator it = mp.begin();
	typename _map<T, V>::iterator it2 = mp.end();
	g_start2 = timer();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int>    reverse_iterators_test_std(std::map<T, V> mp) {
	std::vector<int> v;
//	g_start1 = g_end1 = timer();
//	mp.insert(std::make_pair(5, 5));
//	mp.insert(std::make_pair(3, 3));
//	mp.insert(std::make_pair(7, 7));
//	typename std::map<T, V>::reverse_iterator rit = mp.rbegin(); // 7
//	typename std::map<T, V>::reverse_iterator rit2 = mp.rend(); // .
//	v.push_back(rit->first);
//	rit++;
//	rit2--;
//	v.push_back(rit->first);
//	v.push_back(rit2->first);
//	rit++;
//	v.push_back(*rit == *rit2);
//	rit2--;
//	v.push_back(rit->first);
//	v.push_back(rit2->first);
//	v.push_back(*rit2 > *rit);
//	v.push_back(*rit2 < *rit);
//	v.push_back((--rit)->first);
//	v.push_back((++rit2)->first);
//	v.push_back((rit--)->first);
//	v.push_back((rit2++)->first);
	return v;
}

template <class T, class V>
std::vector<int> reverse_iterators_test_ft(_map<T, V> mp) {
	std::vector<int> v;
//	g_start2 = g_end2 = timer();
//	mp.insert(_make_pair(5, 5));
//	mp.insert(_make_pair(3, 3));
//	mp.insert(_make_pair(7, 7));
//	typename _map<T, V>::reverse_iterator rit = mp.rbegin();
//	typename _map<T, V>::reverse_iterator rit2 = mp.rend();
//	v.push_back(rit->first);
//	rit++;
//	rit2--;
//	v.push_back(rit->first);
//	v.push_back(rit2->first);
//	rit++;
//	v.push_back(*rit == *rit2);
//	rit2--;
//	v.push_back(rit->first);
//	v.push_back(rit2->first);
//	v.push_back(*rit2 > *rit);
//	v.push_back(*rit2 < *rit);
//	v.push_back((--rit)->first);
//	v.push_back((++rit2)->first);
//	v.push_back((rit--)->first);
//	v.push_back((rit2++)->first);
	return v;
}


template <class T, class V>
std::vector<int> copy_constructor_test(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 300000; ++i, ++j) {
		mp.insert(std::make_pair(i, j));
	}
	g_start1 = timer();
	std::map<int, int> mp2(mp.begin(), mp.end());
	g_end1 = timer();
	std::map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 300000; ++i, it++) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> copy_constructor_test(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 300000; ++i, ++j) {
		mp.insert(_make_pair(i, j));
	}
	g_start2 = timer();
	_map<int, int> mp2(mp.begin(), mp.end());
	g_end2 = timer();
	_map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 300000; ++i, it++) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> assign_overload_test(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 200000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<T, V> mp2;
	for (int i = 200000, j = 200010; i < 400000; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	g_start1 = timer();
	mp2 = mp;
	g_end1 = timer();
	typename std::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); it++) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	v.push_back(mp2.size());
	return v;
}

template <class T, class V>
std::vector<int> assign_overload_test(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 10; i < 200000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	_map<T, V> mp2;
	for (int i = 200000, j = 200010; i < 400000; ++i, ++j)
		mp2.insert(_make_pair(i, j));
	g_start2 = timer();
	mp2 = mp;
	g_end2 = timer();
	typename _map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); it++) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	v.push_back(mp2.size());
	return v;
}

template <class T, class V>
std::vector<int> comparator_test(std::map<T, V> mp) {
	std::vector<int> v;
	fillMap(mp);
	for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::greater<int> > mp1;
	fillMap(mp1);
	v.push_back(mp1.begin()->first);
	mp1.erase(41);
	v.push_back(mp1.begin()->first);
	mp1.erase(29);
	v.push_back(mp1.begin()->first);
	std::map<int, int, std::greater<int> > mp2;
	mp2.insert(std::make_pair(3, 3));
	v.push_back(mp2.begin()->first);
	mp2.erase(3);
	if (mp2.begin() == mp2.end())
		v.push_back(1);
	std::map<int, int, std::plus<int> > mp3;
	fillMap(mp3);
	for (typename std::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::minus<int> > mp4;
	fillMap(mp4);
	for (typename std::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::greater_equal<int> > mp5;
	fillMap(mp5);
	for (typename std::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::multiplies<int> > mp6;
	fillMap(mp6);
	for (typename std::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::bit_xor<int> > mp7;
	fillMap(mp7);
	for (typename std::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::logical_and<int> > mp8;
	fillMap(mp8);
	for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
	g_start1 = timer();
	g_end1 = timer();
	v.push_back(mp1.size());
	return v;
}

template <class T, class V>
std::vector<int> comparator_test(_map<T, V> mp) {
	std::vector<int> v;
	fillMap(mp);
	for (typename _map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
	_map<int, int, std::greater<int> > mp1;
	fillMap(mp1);
	v.push_back(mp1.begin()->first);
	mp1.erase(41);
	v.push_back(mp1.begin()->first);
	mp1.erase(29);
	v.push_back(mp1.begin()->first);
	_map<int, int, std::greater<int> > mp2;
	mp2.insert(_make_pair(3, 3));
	v.push_back(mp2.begin()->first);
	mp2.erase(3);
	if (mp2.begin() == mp2.end())
		v.push_back(1);
	_map<int, int, std::plus<int> > mp3;
	fillMap(mp3);
	for (typename _map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
	_map<int, int, std::minus<int> > mp4;
	fillMap(mp4);
	for (typename _map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
	_map<int, int, std::greater_equal<int> > mp5;
	fillMap(mp5);
	for (typename _map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
	_map<int, int, std::multiplies<int> > mp6;
	fillMap(mp6);
	for (typename _map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
	_map<int, int, std::bit_xor<int> > mp7;
	fillMap(mp7);
	for (typename _map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
	for (typename _map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
	std::map<int, int, std::logical_and<int> > mp8;
	fillMap(mp8);
	for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
	for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
	g_start1 = timer();
	g_end1 = timer();
	v.push_back(mp1.size());
	return v;
}

template <class T, class V>
std::vector<int> operator_sq_test(std::map<T, V> mp) {
	std::vector<int> v;
	mp.insert(std::make_pair(3, 3));
	typename std::map<T, V>::iterator it = mp.begin();
	g_start1 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	mp[3] = 10;
	v.push_back(it->first);
	v.push_back(it->second);
	mp[2] = 9;
	it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	it++;
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(mp.size());
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> operator_sq_test(_map<T, V> mp) {
	std::vector<int> v;
	mp.insert(_make_pair(3, 3));
	typename _map<T, V>::iterator it = mp.begin();
	g_start2 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	mp[3] = 10;
	v.push_back(it->first);
	v.push_back(it->second);
	mp[2] = 9;
	it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	it++;
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(mp.size());
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int> empty_test(std::map<T, V> mp) {
	std::vector<int> v;
	g_start1 = timer();
	v.push_back(mp.empty());
	mp.insert(std::make_pair(3, 3));
	v.push_back(mp.empty());
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> empty_test(_map<T, V> mp) {
	std::vector<int> v;
	g_start2 = timer();
	v.push_back(mp.empty());
	mp.insert(_make_pair(3, 3));
	v.push_back(mp.empty());
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int> size_test(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 100000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	g_start1 = timer();
	v.push_back(mp.size());
	g_end1 = timer();
	for (int i = 0; i < 43; ++i)
		mp.erase(i);
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> size_test(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 100000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	g_start2 = timer();
	v.push_back(mp.size());
	g_end2 = timer();
	for (int i = 0; i < 43; ++i)
		mp.erase(i);
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> max_size_test(std::map<T, V> mp) {
	std::vector<int> v;
	g_start1 = timer();
	v.push_back(1);
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> max_size_test(_map<T, V> mp) {
	std::vector<int> v;
	std::map<int, int> std_mp;
	g_start2 = timer();
	if ((std_mp.max_size() / 2) < mp.max_size())
		v.push_back(1);
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int> clear_test(std::map<T, V> mp) {
	std::vector<int> v;
	mp.clear();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	v.push_back(mp.size());
	g_start1 = timer();
	mp.clear();
	g_end1 = timer();
	v.push_back(mp.size());
	typename std::map<T, V>::iterator it = mp.begin();
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> clear_test(_map<T, V> mp) {
	std::vector<int> v;
	mp.clear();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	v.push_back(mp.size());
	g_start2 = timer();
	mp.clear();
	g_end2 = timer();
	v.push_back(mp.size());
	typename _map<T, V>::iterator it = mp.begin();
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> erase_test_1(std::map<T, V> mp) {
	std::vector<int> v;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
	g_start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);
	g_end1 = timer();
	typename std::map<T, V>::iterator it2 = mp.end();
	it2--;
	g_start1 = timer();
	v.push_back(mp.erase(299999));
	g_end1 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> erase_test_1(_map<T, V> mp) {
	std::vector<int> v;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(_make_pair(i, j));
	typename _map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename _map<T, V>::iterator it4 = mp.begin();
	g_start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);
	g_end2 = timer();
	typename _map<T, V>::iterator it2 = mp.end();
	it2--;
	g_start2 = timer();
	v.push_back(mp.erase(299999));
	g_end2 = timer();
	v.push_back(mp.size());
	_map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(_make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	typename _map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> erase_test_2(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
	g_start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
	g_end1 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i) ittest++;
	mp2.erase(ittest);
	for (int i = 0; i < 5; ++i) ittest++;
	mp2.erase(ittest);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> erase_test_2(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(_make_pair(i, j));
	typename _map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename _map<T, V>::iterator it4 = mp.begin();
	g_start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
	g_end2 = timer();
	v.push_back(mp.size());
	_map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(_make_pair(i, j));
	typename _map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i) ittest++;
	mp2.erase(ittest);
	for (int i = 0; i < 5; ++i) ittest++;
	mp2.erase(ittest);
	typename _map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> erase_test_3(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(std::make_pair(i, j));

	std::map<int, int>::iterator it = mp.begin();
	g_start1 = timer();
	mp.erase(mp.begin(), --mp.end());
	g_end1 = timer();
	v.push_back(mp.begin()->first);
	return v;
}

template <class T, class V>
std::vector<int> erase_test_3(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(_make_pair(i, j));

	_map<int, int>::iterator it = mp.begin();
	g_start2 = timer();
	mp.erase(mp.begin(), --mp.end());
	g_end2 = timer();
	v.push_back(mp.begin()->first);
	return v;
}

template <class T, class V>
std::vector<int> swap_test(std::map<T, V> mp) {
	std::vector<int> v;
	g_start1 = g_end1 = timer();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<T, V> mp2;
	for (int i = 250000, j = 0; i < 350000; ++i, --j)
		mp.insert(std::make_pair(i, j));
	mp.swap(mp2);
	v.push_back(mp2.size());
	typename std::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	std::swap(mp, mp2);
	typename std::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> swap_test(_map<T, V> mp) {
	std::vector<int> v;
	g_start2 = g_end2 = timer();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(_make_pair(i, j));
	_map<T, V> mp2;
	for (int i = 250000, j = 0; i < 350000; ++i, --j)
		mp.insert(_make_pair(i, j));
	mp.swap(mp2);
	v.push_back(mp2.size());
	typename _map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it) {
		v.push_back(it->first);
		v.push_back(it->second);
	}
	std::swap(mp, mp2);
	typename _map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> count_test(std::map<T, V> mp) {
	std::vector<int> v;
	g_start1 = g_end1 = timer();
	v.push_back(mp.count(0));
	mp.insert(std::make_pair(0, 0));
	v.push_back(mp.count(0));
	return v;
}

template <class T, class V>
std::vector<int> count_test(_map<T, V> mp) {
	std::vector<int> v;
	g_start2 = g_end2 = timer();
	v.push_back(mp.count(0));
	mp.insert(_make_pair(0, 0));
	v.push_back(mp.count(0));
	return v;
}

template <class T, class V>
std::vector<int> find_test(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = -750000, j = 0; i < 750000; ++i, ++j) {
		mp.insert(std::make_pair(i, j));
	}
	g_start1 = timer();
	typename std::map<T, V>::iterator it = mp.find(345678);
	g_end1 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-345678);
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-987654321);
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> find_test(_map<T, V> mp) {
	std::vector<int> v;
	for (int i = -750000, j = 0; i < 750000; ++i, ++j) {
		mp.insert(_make_pair(i, j));
	}
	g_start2 = timer();
	typename _map<T, V>::iterator it = mp.find(345678);
	g_end2 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-345678);
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-987654321);
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> lower_bound_test(std::map<T, V> mp) {
	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(std::make_pair(i, j));
	}
	g_start1 = timer();
	mp3.lower_bound(490000);
	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> lower_bound_test(_map<T, V> mp) {
	std::vector<int> v;
	_map<int, int, std::greater<int> > mp2;
	mp.insert(_make_pair(10, 10));
	mp2.insert(_make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(_make_pair(20, 20));
	mp.insert(_make_pair(30, 30));
	mp.insert(_make_pair(40, 40));
	mp.insert(_make_pair(50, 50));
	mp.insert(_make_pair(60, 60));
	mp2.insert(_make_pair(20, 20));
	mp2.insert(_make_pair(30, 30));
	mp2.insert(_make_pair(40, 40));
	mp2.insert(_make_pair(50, 50));
	mp2.insert(_make_pair(60, 60));
	_map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	_map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(_make_pair(i, j));
	}
	g_start2 = timer();
	mp3.lower_bound(490000);
	g_end2 = timer();
	return v;
}

template <class T, class V>
		std::vector<int> upper_bound_test(std::map<T, V> mp) {
	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.upper_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.upper_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.upper_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.upper_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(std::make_pair(i, j));
	}
	std::map<int, int> mp4;
	mp.insert(std::make_pair(-10, 10));
	mp.insert(std::make_pair(-20, 20));
	v.push_back((--mp.upper_bound(0))->first);
	g_start1 = timer();
	mp3.upper_bound(490000);
	g_end1 = timer();
	return v;
}

template <class T, class V>
		std::vector<int> upper_bound_test(_map<T, V> mp) {
	std::vector<int> v;
	_map<int, int, std::greater<int> > mp2;
	mp.insert(_make_pair(10, 10));
	mp2.insert(_make_pair(10, 10));
	if (mp.upper_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.upper_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(_make_pair(20, 20));
	mp.insert(_make_pair(30, 30));
	mp.insert(_make_pair(40, 40));
	mp.insert(_make_pair(50, 50));
	mp.insert(_make_pair(60, 60));
	mp2.insert(_make_pair(20, 20));
	mp2.insert(_make_pair(30, 30));
	mp2.insert(_make_pair(40, 40));
	mp2.insert(_make_pair(50, 50));
	mp2.insert(_make_pair(60, 60));
	_map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.upper_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.upper_bound(i);
		v.push_back(it->first);
	}
	_map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(_make_pair(i, j));
	}
	_map<int, int> mp4;
	mp.insert(_make_pair(-10, 10));
	mp.insert(_make_pair(-20, 20));
	v.push_back((--mp.upper_bound(0))->first);
	g_start2 = timer();
	mp3.upper_bound(490000);
	g_end2 = timer();
	return v;
}

template <class T, class V>
std::vector<int> equal_range_test(std::map<T, V> mp) {
	std::vector<int> v;
	mp.insert(std::make_pair(10, 10));
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	g_start1 = timer();
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair = mp.equal_range(10);
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair2 = mp.equal_range(11);
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair3 = mp.equal_range(1);
	g_end1 = timer();
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second->first);
	v.push_back(pair.second->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second->first);
	v.push_back(pair2.second->second);
	v.push_back(pair3.first->first);
	v.push_back(pair3.first->second);
	v.push_back(pair3.second->first);
	v.push_back(pair3.second->second);
	return v;
}

template <class T, class V>
std::vector<int> equal_range_test(_map<T, V> mp) {
	std::vector<int> v;
	mp.insert(_make_pair(10, 10));
	mp.insert(_make_pair(20, 20));
	mp.insert(_make_pair(30, 30));
	mp.insert(_make_pair(40, 40));
	mp.insert(_make_pair(50, 50));
	mp.insert(_make_pair(60, 60));
	g_start2 = timer();
	const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair = mp.equal_range(10);
	const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair2 = mp.equal_range(11);
	const _pair<_map<int, int>::const_iterator , _map<int, int>::const_iterator>& pair3 = mp.equal_range(1);
	g_end2 = timer();
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second->first);
	v.push_back(pair.second->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second->first);
	v.push_back(pair2.second->second);
	v.push_back(pair3.first->first);
	v.push_back(pair3.first->second);
	v.push_back(pair3.second->first);
	v.push_back(pair3.second->second);
	return v;
}

template <class T, class V>
std::vector<int> key_comp_test(std::map<T, V> mp) {
	std::vector<int> v;
	g_start1 = g_end1 = timer();
	std::map<int, int, std::greater<int> > mp2;
	std::map<int, int, std::equal_to<int> > mp3;
	v.push_back(mp.key_comp()(1, 2));
	v.push_back(mp2.key_comp()(1, 2));
	v.push_back(mp3.key_comp()(1, 2));
	return v;
}

template <class T, class V>
std::vector<int> key_comp_test(_map<T, V> mp) {
	std::vector<int> v;
	g_start2 = g_end2 = timer();
	_map<int, int, std::greater<int> > mp2;
	_map<int, int, std::equal_to<int> > mp3;
	v.push_back(mp.key_comp()(1, 2));
	v.push_back(mp2.key_comp()(1, 2));
	v.push_back(mp3.key_comp()(1, 2));
	return v;
}

bool is_integral_test_() {
	std::vector<int> v;
	bool res = 1;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	(_is_integral<float>::value == std::is_integral<float>()) ? 0 : res = 0;
	(_is_integral<int>::value == std::is_integral<int>()) ? 0 : res = 0;
	(_is_integral<bool>::value == std::is_integral<bool>()) ? 0 : res = 0;
	(_is_integral<char>::value == std::is_integral<char>()) ? 0 : res = 0;
	(_is_integral<signed char>::value == std::is_integral<signed char>()) ? 0 : res = 0;
	(_is_integral<unsigned char>::value == std::is_integral<unsigned char>()) ? 0 : res = 0;
	(_is_integral<wchar_t>::value == std::is_integral<wchar_t>()) ? 0 : res = 0;
	(_is_integral<char16_t>::value == std::is_integral<char16_t>()) ? 0 : res = 0;
	(_is_integral<short>::value == std::is_integral<short>()) ? 0 : res = 0;
	(_is_integral<unsigned short>::value == std::is_integral<unsigned short>()) ? 0 : res = 0;
	(_is_integral<unsigned int>::value == std::is_integral<unsigned int>()) ? 0 : res = 0;
	(_is_integral<long>::value == std::is_integral<long>()) ? 0 : res = 0;
	(_is_integral<unsigned long>::value == std::is_integral<unsigned long>()) ? 0 : res = 0;
	(_is_integral<long long>::value == std::is_integral<long long>()) ? 0 : res = 0;
	(_is_integral<unsigned long long>::value == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	return res;
}

template <class T> typename _enable_if< std::is_unsigned<T>::value >::type
		foo(T) {
	g_start1 = -20;
}

template <class T> typename _enable_if< std::is_signed<T>::value >::type
		foo(T) {
	g_start2 = -20;
}

bool enable_if_test_() {
	std::vector<int> v;
	bool res = 1;
	unsigned int xx = 5;
	int x = 5;
	foo(xx);
	foo(x);
	if (g_start1 != -20 && g_start2 != -20)
		res = 0;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	return res;
}

bool equal_test() {
	std::string s = "approvjvorppa";
	bool res = 0;
	if (ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) == 1)
		res = 1;
	return res;
}

bool lexicographical_test() {
	std::vector<int> result, result2;
	std::vector<char> v1, v2;
	_vector<char> b1, b2;
	v1.assign(50000000, 'f');
	v1.push_back('e');
	v2.assign(50000000, 'f');
	v2.push_back('e');
	b1.assign(50000000, 'f');
	b1.push_back('e');
	b2.assign(50000000, 'f');
	b2.push_back('e');
	g_start1 = timer();
	result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	g_end1 = timer();
	g_start2 = timer();
	result2.push_back(ft::lexicographical_compare(b1.begin(), b1.end(), b2.begin(), b2.end()));
	g_end2 = timer();
	return result == result2;
}

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	} catch (...) { pclose(pipe); throw; }
	pclose(pipe);
	return result;
}

std::string get_leak_string(std::string s) {
	std::string tmp;
	int idx = s.find("total leaked bytes");
	for (; s[idx] != '\n' ; --idx) {}
	int edx = idx + 1;
	for (; s[edx] != '\n' ; ++edx) {}
	return s.substr(++idx, edx - 101);
}

void leaks_test() {
	string a = "leaks ";
	a += _exec_name;
	usleep(50);
	string s = get_leak_string(exec(a.c_str()));
	cout << YELLOW + s.substr(0, s.length() - 2) + RESET << endl;
}

void MyAlarm (int a) { kill(pid, SIGTERM); timeout_flag = 1;  }

void printElement(const std::string& t) {
	if (t == "OK") { cout << GREEN; }
	else if (t == "FAILED") { cout << REDD; }
	cout << std::left << std::setw(25) << std::setfill(' ') << t;
	cout << RESET;
}

void run_bool_unit_test(std::string test_name, bool (func1)()) {
	time_t t1;
	time_t t2;
	int status;
	bool res;

	alarm(7);
	pid = fork();
	if (!pid) {
		printElement(test_name);
		res = func1();
		(res) ? printElement("OK") : printElement("FAILED");
		t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
		(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
		(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
		cout << endl;
		exit(0);
	}
	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	if (WIFSTOPPED(status)) {
		printElement(YELLOW + "STOPPED" + RESET);
	} else if (WIFSIGNALED(status)) {
		if (timeout_flag) {
			timeout_flag = 0;
			printElement(test_name);
			printElement(YELLOW + "TIMEOUT" + RESET);
		} else {
			printElement(test_name);
			printElement(REDD + "SEGFAULT" + RESET);
		}
		cout << endl;
	}
}

template <class T>
void run_vector_unit_test(std::string test_name, std::vector<int> (func1)(std::vector<T>), std::vector<int> (func2)(_vector<T>)) {
	time_t t1;
	time_t t2;
	int status;
	std::vector<int > res1;
	std::vector<int > res2;
	std::vector<int> vector;
	_vector<int> my_vector;

	alarm(7);
	pid = fork();
	if (!pid) {
		printElement(test_name);
		res1 = func1(vector);
		res2 = func2(my_vector);
		(res1 == res2) ? printElement("OK") : printElement("FAILED");
		t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
		(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
		(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
		cout << endl;
		exit(0);
	}
	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	if (WIFSTOPPED(status)) {
		printElement(YELLOW + "STOPPED" + RESET);
	} else if (WIFSIGNALED(status)) {
		if (timeout_flag) {
			timeout_flag = 0;
			printElement(test_name);
			printElement(YELLOW + "TIMEOUT" + RESET);
		} else {
			printElement(test_name);
			printElement(REDD + "SEGFAULT" + RESET);
		}
		cout << endl;
	}
}

template <class T, class V>
void run_map_unit_test(std::string test_name, std::vector<int> (func1)(std::map<T, V>), std::vector<int> (func2)(_map<T, V>)) {
	time_t t1;
	time_t t2;
	int status;
	std::vector<int > res1;
	std::vector<int > res2;
	std::map<int, int> map;
	_map<int, int> my_map;

	alarm(7);
	pid = fork();
	if (!pid) {
		printElement(test_name);
		res1 = func1(map);
		res2 = func2(my_map);
		(res1 == res2) ? printElement("OK") : printElement("FAILED");
		t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
		(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
		(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
		cout << endl;
		exit(0);
	}
	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	if (WIFSTOPPED(status)) {
		printElement(YELLOW + "STOPPED" + RESET);
	} else if (WIFSIGNALED(status)) {
		if (timeout_flag) {
			timeout_flag = 0;
			printElement(test_name);
			printElement(YELLOW + "TIMEOUT" + RESET);
		} else {
			printElement(test_name);
			printElement(REDD + "SEGFAULT" + RESET);
		}
		cout << endl;
	}
}