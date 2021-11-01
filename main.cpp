#include <iostream>
using std::cout;
using std::endl;
#include <stack>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "Map.hpp"
#include "Set.hpp"
#include "Vector.hpp"
#include "Stack.hpp"

/*
 *
 * ✅ 1. Переписать всё на аллокатор
 * ✅ 2. Решить, что делать с pair const
 * ✅ 3. Реализовать value compare
 * ✅ 4. перегрузка сравнения
 * ✅ 5. проверить живой ли вектор
 * ☑️ 6. проверить выбрасываемые исключения для вектора и мапы
 * ✅ 7. Починить insert hint
 * ✅ 8. Написать тесты для стека
 * ✅ 9. Написать Set
 * ☑️ 10. Изменение ключа у мапы!!!
 * ✅ 11. Возможность тестировать контейнеры независимо от наличия других
 * ✅ 12. Проверить, что swap не меняет сами адреса
 *
 * */


int main (void) {
	std::deque<int> deq;
	ft::Stack<int> st(deq);
	return (0);
}