#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                       VECTOR                                    |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../vector_tests/vector_constructor.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_iterators.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_begin().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_end().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_rbegin().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_rend().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_size().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_max_size().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_resize().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_capacity().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_empty().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_reserve().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator[].cpp", argv, env);
	runFunctionTest("../vector_tests/vector_at().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_front().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_back().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_assign().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_push_back().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_pop_back().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_insert(single).cpp", argv, env);
	runFunctionTest("../vector_tests/vector_insert(fill).cpp", argv, env);
	runFunctionTest("../vector_tests/vector_insert(range).cpp", argv, env);
	runFunctionTest("../vector_tests/vector_erase(value).cpp", argv, env);
	runFunctionTest("../vector_tests/vector_erase(range).cpp", argv, env);
	runFunctionTest("../vector_tests/vector_swap().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_clear().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_data().cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator==.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator!=.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator<.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator>.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator<=.cpp", argv, env);
	runFunctionTest("../vector_tests/vector_operator>=.cpp", argv, env);

	return 0;
}