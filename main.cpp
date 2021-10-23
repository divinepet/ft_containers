#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"




int main(int argc, char **argv) {


	start_tests();


//	std::map<int, int, std::less<int> > mp;
//	mp.insert(std::make_pair(10, 10));
//	mp.insert(std::make_pair(20, 20));
////	mp.insert(ft::make_pair(-10, 10));
////	mp.insert(ft::make_pair(-20, 20));
//	mp.insert(std::make_pair(30, 30));
//	mp.insert(std::make_pair(40, 40));
//	mp.insert(std::make_pair(50, 50));
//	mp.insert(std::make_pair(60, 60));
//
//	std::pair<std::map<int, int>::iterator , std::map<int, int>::iterator> pair = mp.equal_range(13);
//	cout << pair.first->first << endl;
//	cout << pair.second->first << endl;


//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(10, 10));
//	mp.insert(ft::make_pair(20, 20));
//	mp.insert(ft::make_pair(30, 30));
//	mp.insert(ft::make_pair(40, 40));
//	mp.insert(ft::make_pair(50, 50));
//	mp.insert(ft::make_pair(60, 60));
//
//	mp = const_cast<const ft::Map<int, int>& >(mp);
//
//	const ft::pair<ft::Map<int, int>::const_iterator , ft::Map<int, int>::const_iterator>& pair = mp.equal_range(10);
//	cout << pair.first->first << endl;
//	cout << pair.second->first << endl;







//	// todo реалзиовать insert с хинтом
//	std::map<int , int> mp;
//	std::map<int, int>::iterator it = mp.end();
//
//	g_start1 = timer();
//	for (int i = 0, j = 0; i < 600000; ++i, ++j) {
//		it = mp.insert(it, std::make_pair(i, j));
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
