#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include <set>
#include "Map.hpp"
#include "Set.hpp"
//#sources "ft_containers_tests/start_tests.hpp"
//#include "ft_containers_unit_tests/start_tests.hpp"


template <class T, class V>
void print(std::map<T, V> mp) { for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) cout << "key: " << it->first << ", value: " << it->second << endl; }

template <class T, class V>
void print(ft::Map<T, V> mp) { for (typename ft::Map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) cout << "key: " << it->first << ", value: " << it->second << endl; }

/*
 * 1. По окончанию теста подсказать про логи
 *
 * */

/*
 *
 * ✅ 1. Переписать всё на аллокатор
 * ✅ 2. Решить, что делать с pair const
 * ✅ 3. Реализовать value compare
 * ✅ 4. перегрузка сравнения
 * ✅ 5. проверить живой ли вектор
 * ☑️ 6. проверить выбрасываемые исключения для вектора и мапы
 * ☑️ 7. Починить insert hint
 * ☑️ 8. Написать тесты для стека
 * ☑️ 9. Написать Set
 *
 * */


int main(int argc, char *argv[]) {


	cout << output << endl;
}