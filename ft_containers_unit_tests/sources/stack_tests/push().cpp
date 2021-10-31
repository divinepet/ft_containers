#include "../system/lib.hpp"

template <class T>
std::vector<int> size_test(std::stack<T> stk) {
	std::vector<int> v;
	g_start1 = timer();
	for (int i = 0; i < 8000000; ++i)
		stk.push(i);
	g_end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> size_test(_stack<T> stk) {
	std::vector<int> v;
	g_start2 = timer();
	for (int i = 0; i < 8000000; ++i)
		stk.push(i);
	g_end2 = timer();
	v.push_back(stk.size());
	return v;
}

int main() {

	run_stack_unit_test<int>("push()", size_test, size_test);

	return (0);
}