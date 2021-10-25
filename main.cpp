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



int main(int argc, char **argv) {

	ft::Map<int, int> mp;
	for (int i = 0, j = 0; i < 133; ++i, ++j) {
		mp.insert(ft::make_pair(i ,j ));
	}
	ft::Map<int, int>::iterator it = mp.begin();

	for (; it != mp.end(); it++)
		cout << it->first << endl;

//	mp.erase(mp.begin(), mp.end());

//	print(mp);



//	ft::Map<int, int, std::greater<int> > mp2;
//	mp2.insert(ft::make_pair(3, 3));
//	cout << mp2.begin()->first << endl;
//	mp2.erase(3);
//	cout << mp2.begin()->first << endl;
//	if (mp2.begin() == mp2.end())
//		cout << "is equal" << endl;

//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(3, 3));
//	mp.insert(ft::make_pair(5, 5));
//	mp.insert(ft::make_pair(7, 7));
//
//	ft::Map<int, int>::reverse_iterator rit = mp.rend();
//	rit--;
//	cout << rit->first << endl;

//	start_tests();

//	std::map<int, int> mp;
//
//	for (int i = 0, j = 0; i < 500000; ++i, ++j)
//		mp.insert(std::make_pair(i, j));
//
//	mp.erase(mp.begin(), --mp.end());
//	print(mp);
}
