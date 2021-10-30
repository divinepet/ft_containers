#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
//	cout << "-----------------------------------------------------------------------------------" << endl;
//	cout << "|                                     ALGORITHMS                                  |" << endl;
//	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                         MAP                                      |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../map_tests/map_constructor.cpp", argv, env);
	runFunctionTest("../map_tests/map_assign_overload.cpp", argv, env);
	runFunctionTest("../map_tests/map_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/map_reverse_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/map_comparator.cpp", argv, env);
	runFunctionTest("../map_tests/map_insert_value.cpp", argv, env);
	runFunctionTest("../map_tests/map_insert_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/map_insert_hint.cpp", argv, env);
	runFunctionTest("../map_tests/map_at.cpp", argv, env);
	runFunctionTest("../map_tests/map_operator[].cpp", argv, env);
	runFunctionTest("../map_tests/map_empty.cpp", argv, env);
	runFunctionTest("../map_tests/map_size.cpp", argv, env);
	runFunctionTest("../map_tests/map_max_size.cpp", argv, env);
	runFunctionTest("../map_tests/map_clear.cpp", argv, env);
	runFunctionTest("../map_tests/map_erase_key.cpp", argv, env);
	runFunctionTest("../map_tests/map_erase_pos.cpp", argv, env);
	runFunctionTest("../map_tests/map_erase_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/map_swap.cpp", argv, env);
	runFunctionTest("../map_tests/map_count.cpp", argv, env);
	runFunctionTest("../map_tests/map_find.cpp", argv, env);
	runFunctionTest("../map_tests/map_lower_bound.cpp", argv, env);
	runFunctionTest("../map_tests/map_upper_bound.cpp", argv, env);
	runFunctionTest("../map_tests/map_equal_range.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);

	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/map_key_comp.cpp", argv, env);


	return (0);
}