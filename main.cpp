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


/*
 *
 * 1. П̶е̶р̶е̶п̶и̶с̶а̶т̶ь̶ ̶в̶с̶ё̶ ̶н̶а̶ ̶а̶л̶л̶о̶к̶а̶т̶о̶р
 * 2. Решить, что делать с pair const
 * 3. v̶a̶l̶u̶e̶ ̶c̶o̶m̶p̶a̶r̶e
 * 4. перегрузка сравнения
 * 5. проверить живой ли вектор
 * 6. проверить выбрасываемые исключения для вектора и мапы
 *
 * */

int main(int argc, char **argv) {
//	const ft::Map<int, int > mp;
//	ft::Map<int, int >::const_iterator it = mp.begin();

//	const std::map<int, int > mp;
//	std::map<int, int >::const_iterator it = mp.begin();

//	mp.insert(ft::make_pair(3, 3));
//

//	std::map<int, int> mp;
//	mp.insert(std::make_pair(3, 3));
//	std::map<int, int >::iterator it = mp.begin();
//	(*it).second = 6;
//	it->first = 5;
//
//	ft::Map<int, int> mp2;
//	mp2.insert(ft::make_pair(3, 3));
//
//	cout << (mp == mp2) << endl;

	start_tests();

	return 0;
}
