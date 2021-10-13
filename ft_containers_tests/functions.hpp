time_t g_start1;
time_t g_start2;
time_t g_end1;
time_t g_end2;

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string RESET = "\033[0m";

using std::string;
using std::cout;
using std::endl;

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
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
std::vector<int> constructor_test(ft::Vector<T> vector) {
	std::vector<int> v;
	ft::Vector<int> tmp(4, 4), tmp2(5, 5);
	tmp = tmp;
	tmp = tmp2;
	ft::Vector<int> tmp3(tmp);
	ft::Vector<int> tmp4(tmp.begin(), tmp.end());
	v.push_back(tmp4.size());
	v.push_back(tmp4.capacity());
	v.push_back(tmp[2]);
	v.push_back(tmp3[2]);
	v.push_back(tmp4[2]);
	try { ft::Vector<int> tmp5(-1, -1); }
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
std::vector<int> push_back_test(ft::Vector<T> vector) {
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
std::vector<int> at_test(ft::Vector<T> vector) {
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
std::vector<int> assign_test(ft::Vector<T> vector) {
	std::vector<int> v;
	ft::Vector<int> tmp, tmp2;
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
std::vector<int> operator1_test(ft::Vector<T> vector) {
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
std::vector<int> front_test(ft::Vector<T> vector) {
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
std::vector<int> back_test(ft::Vector<T> vector) {
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
std::vector<int> reserve_test(ft::Vector<T> vector) {
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
std::vector<int> insert_test_1(ft::Vector<T> vector) {
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
std::vector<int> insert_test_2(ft::Vector<T> vector) {
	std::vector<int> v;
	ft::Vector<int> tmp;
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
std::vector<int> insert_test_3(ft::Vector<T> vector) {
	std::vector<int> v;
	ft::Vector<int> tmp;
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
std::vector<int> erase_test_1(ft::Vector<T> vector) {
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
std::vector<int> erase_test_2(ft::Vector<T> vector) {
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
std::vector<int> data_test(ft::Vector<T> vector) {
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
std::vector<int> begin_test(ft::Vector<T> vector) {
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
std::vector<int> end_test(ft::Vector<T> vector) {
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
std::vector<int> rbegin_test(ft::Vector<T> vector) {
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
std::vector<int> rend_test(ft::Vector<T> vector) {
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
std::vector<int> empty_test(ft::Vector<T> vector) {
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
std::vector<int> size_test(ft::Vector<T> vector) {
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
std::vector<int> capacity_test(ft::Vector<T> vector) {
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
std::vector<int> maxsize_test(ft::Vector<T> vector) {
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
std::vector<int> pop_back_test(ft::Vector<T> vector) {
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
std::vector<int> resize_test(ft::Vector<T> vector) {
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
std::vector<int> swap_test(ft::Vector<T> vector) {
	std::vector<int> v;
	vector.assign(11000000, 11);
	ft::Vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
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
std::vector<int> clear_test(ft::Vector<T> vector) {
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
std::vector<int> iterator_test(ft::Vector<T> vector) {
	typename ft::Vector<T>::iterator it;
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
	std::vector<int> v_int1, v_int2, v_int3;	ft::Vector<int> V_int1, V_int2, V_int3;
	std::vector<string> v_str1, v_str2;			ft::Vector<string> V_str1, V_str2;
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
	ft::Vector<int> V_int1, V_int2, V_int3;
	ft::Vector<string> V_str1, V_str2;
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
	ft::Vector<int> V_int1, V_int2, V_int3;
	ft::Vector<string> V_str1, V_str2;
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
	ft::Vector<int> V_int1, V_int2, V_int3;
	ft::Vector<string> V_str1, V_str2;
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
	ft::Vector<int> V_int1, V_int2, V_int3;
	ft::Vector<string> V_str1, V_str2;
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
	ft::Vector<int> V_int1, V_int2, V_int3;
	ft::Vector<string> V_str1, V_str2;
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

//template <class T, class V>
//std::vector<int> insert_test(std::map<T, V> mp) {
//	std::vector<int> v;
//	std::pair<std::map<int, int>::iterator , bool> pair = mp.insert(std::make_pair(7, 7));
//	std::map<int, int>::iterator it = mp.begin();
//	v.push_back(it->first);
//	v.push_back(it->second);
//	v.push_back(pair.first->first);
//	v.push_back(pair.first->second);
//	v.push_back(pair.second);
//	mp.insert(std::make_pair(9, 9));
//	std::pair<std::map<int, int>::iterator , bool> pair2 = mp.insert(std::make_pair(9, 9));
//	std::map<int, int>::iterator it2 = pair.first;
//	v.push_back(it2->first);
//	v.push_back(it2->second);
//	v.push_back(pair2.first->first);
//	v.push_back(pair2.first->second);
//	v.push_back(pair2.second);
//	g_start1 = timer();
//	for (int i = 0, j = 0; i < 100000; ++i, ++j) {
//		mp.insert(std::make_pair(i, j));
//	}
//	g_end1 = timer();
//	v.push_back(mp.size());
//	return v;
//}
//
//template <class T, class V>
//std::vector<int> insert_test(ft::Map<T, V> mp) {
//	std::vector<int> v;
//	ft::pair<ft::Map<int, int>::iterator , bool> pair = mp.insert(ft::make_pair(7, 7));
//	ft::Map<int, int>::iterator it = mp.begin();
//	v.push_back(it->first);
//	v.push_back(it->second);
//	v.push_back(pair.first->first);
//	v.push_back(pair.first->second);
//	v.push_back(pair.second);
//	mp.insert(ft::make_pair(9, 9));
//	ft::pair<ft::Map<int, int>::iterator , bool> pair2 = mp.insert(ft::make_pair(9, 9));
//	ft::Map<int, int>::iterator it2 = pair.first;
//	v.push_back(it2->first);
//	v.push_back(it2->second);
//	v.push_back(pair2.first->first);
//	v.push_back(pair2.first->second);
//	v.push_back(pair2.second);
//	g_start2 = timer();
//	for (int i = 0, j = 0; i < 100000; ++i, ++j) {
//		mp.insert(ft::make_pair(i, j));
//	}
//	g_end2 = timer();
//	v.push_back(mp.size());
//	return v;
//}

int is_integral_test_() {
	std::vector<int> v;
	int res = 0;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	(ft::is_integral<float>() == std::is_integral<float>()) ? 0 : res = 1;
	(ft::is_integral<int>() == std::is_integral<int>()) ? 0 : res = 1;
	(ft::is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 1;
	(ft::is_integral<char>() == std::is_integral<char>()) ? 0 : res = 1;
	(ft::is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 1;
	(ft::is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 1;
	(ft::is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 1;
	(ft::is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 1;
	(ft::is_integral<short>() == std::is_integral<short>()) ? 0 : res = 1;
	(ft::is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 1;
	(ft::is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 1;
	(ft::is_integral<long>() == std::is_integral<long>()) ? 0 : res = 1;
	(ft::is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 1;
	(ft::is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 1;
	(ft::is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 1;
	return res;
}

template <class T> typename ft::enable_if< std::is_unsigned<T>::value >::type
		foo(T) {
	g_start1 = -20;
}

template <class T> typename ft::enable_if< std::is_signed<T>::value >::type
		foo(T) {
	g_start2 = -20;
}

int enable_if_test_() {
	std::vector<int> v;
	int res = 0;
	unsigned int xx = 5;
	int x = 5;
	foo(xx);
	foo(x);
	if (g_start1 != -20 && g_start2 != -20)
		res = 1;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	return res;
}

int equal_test() {
	std::string s = "approvjvorppa";
	int res = 1;
	if (ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) == 1)
		res = 0;
	return res;
}

int lexicographical_test() {
	std::vector<int> result, result2;
	std::vector<char> v1, v2;
	ft::Vector<char> b1, b2;
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
	a += cmd_name;
	usleep(50);
	string s = get_leak_string(exec(a.c_str()));
	cout << YELLOW + s.substr(0, s.length() - 2) + RESET << endl;
}

void printElement(const std::string& t) {
	if (t == "OK") { cout << GREEN; }
	else if (t == "FAILED") { cout << REDD; }
	cout << std::left << std::setw(25) << std::setfill(' ') << t;
	cout << RESET;
}