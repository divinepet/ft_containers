#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include <unistd.h>
#include "ft_containers_tests/start_tests.hpp"


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


int main(int argc, char *argv[]) {


	start_tests();
	return 0;
}