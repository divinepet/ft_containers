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

template <class T>
void test(T type) {

}


int main(int argc, char **argv) {


	test("asd");

//	start_tests();

//	std::map<int, int> mp;
//
//	for (int i = 0, j = 0; i < 500000; ++i, ++j)
//		mp.insert(std::make_pair(i, j));
//
//	mp.erase(mp.begin(), --mp.end());
//	print(mp);
}
