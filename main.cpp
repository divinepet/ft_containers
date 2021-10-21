#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"

int main(int argc, char **argv) {
	ft::Map<int, int > mp1;

	mp1.insert(ft::make_pair(17, 17));
	mp1.insert(ft::make_pair(7, 7));
	mp1.insert(ft::make_pair(3, 3));
	mp1.insert(ft::make_pair(14, 14));

	ft::Map<int, int>::iterator it = mp1.begin();

	for (; it != mp1.end(); it++) {
		std::cout << it->first << std::endl;
	}
//	std::map<int , int> mp;
//	std::map<int, int>::iterator it = mp.end();
//
//	g_start1 = timer();
//	for (int i = 0, j = 0; i < 600000; ++i, ++j) {
//		mp.insert(it, std::make_pair(i, j));
////		mp.insert(std::make_pair(i, j));
//	}
//	g_end1 = timer();
//
//	cout << g_end1 - g_start1 << "ms" << endl;

//	std::map<int, int>::iterator it2 = mp.begin();
//	for (; it2 != mp.end(); it2++) {
//		cout << "key: " << it2->first << ", value: " << it2->second << endl;
//	}




//	std::map<int , int> mp;
//	std::map<int, int>::iterator it = mp.begin();
//
//	g_start1 = timer();
//	for (int i = 0, j = 0; i < 600000; ++i, ++j) {
//		it = mp.insert(it, std::make_pair(i, j));
////		mp.insert(std::make_pair(i, j));
//	}
//	g_end1 = timer();
//
//	cout << g_end1 - g_start1 << "ms" << endl;

//	start_tests();
//	ft_leaks();
}
