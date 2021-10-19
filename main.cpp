#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"

//template <class T, class V>
//void print(std::map<T, V> map) {
//	typename std::map<T, V>::iterator it = map.begin();
//	for (; it != map.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}
//
//template <class T, class V>
//void print(ft::Map<T, V> map) {
//	typename ft::Map<T, V>::iterator it = map.begin();
//	for (; it != map.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}

std::string ft_exec(const char* cmd) {
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

std::string ft_get_leak_string(std::string s) {
	std::string tmp;
	int idx = s.find("total leaked bytes");
	for (; s[idx] != '\n' ; --idx) {}
	int edx = idx + 1;
	for (; s[edx] != '\n' ; ++edx) {}
	return s.substr(++idx, edx - 101);
}

void ft_leaks() {
	string a = "leaks ";
	a += cmd_name;
	usleep(50);
	string s = ft_get_leak_string(ft_exec(a.c_str()));
	cout << YELLOW + s.substr(0, s.length() - 2) + RESET << endl;
}


#include <type_traits>

//template <class T, class V>
//ft::Map<T, V>


//template <class T, class V>
//ft::Map<T, V> f1(ft::Map<T, V> mp) {
//	mp.insert(ft::make_pair(4, 4));
//	ft::Map<int ,int>::iterator it = mp.begin();
//	cout << it->first << endl;
//	return mp;
//}

//template <class T, class V>
//std::vector<int> f1(Tree<T ,V> tree) {
//	std::vector<int> v;
//	for (int i = 0, j = 10; i < 300000; ++i, ++j)
//		tree.insertNode(i, j);
//	return v;
//}

//void ft_map_tests() {
//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(8, 8));
//	mp = f1(mp);
//	ft::Map<int ,int>::iterator it = mp.begin();
//	cout << it->first << endl;
//}

int main(int argc, char **argv) {

//	std::map<int, int> m;
//	m.insert(std::make_pair(1, 1));
//	m.insert(std::make_pair(2, 2));

//	std::map<int, int> m2(m.end(), m.begin());
	ft::Map<int, int> mp;
	for (int i = 0, j = 10; i < 33000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));

	ft::Map<int, int> mp2(mp.begin(), mp.end());

	ft::Map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 33000; ++i, it++) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}


//	start_tests();
//	ft_map_tests();
//ft_leaks();
}
