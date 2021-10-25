#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"

template <class T, class V>
void print(std::map<T, V> mp) { for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) cout << "key: " << it->first << ", value: " << it->second << endl; }

template <class T, class V>
void print(ft::Map<T, V> mp) { for (typename ft::Map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) cout << "key: " << it->first << ", value: " << it->second << endl; }

//				    rbegin
//				   ++ . --
//				  3 5 7

//				     rend
//				   ++ . --
//				      x 3 5 7


void test(int *n) {
	*n = 5;
}

int main(int argc, char **argv) {
//	ft::Map<int, int> mp;
//	std::map<int, int> mp;


//	mp.insert(std::make_pair(3, 3));
//	std::map<int, int>::iterator it = mp.begin();
//	mp.erase(3);
//	cout << it->first << endl;
//	for (int i = 0, j = 0; i < 300000; ++i, ++j)
//		mp.insert(ft::make_pair(i, j));
//
//	mp.erase(mp.begin(), --mp.end());;
//		it++;
//	}

//	for (; it != mp.end(); ++it)
//		mp.erase(it);
//		mp.erase(mp.begin(), --mp.end());


	start_tests();
}
