#pragma once
#include "lib.hpp"

void start_tests() {
	cout << "************************************************************************" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                    ft_containers TESTS by @elaronda                  *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "************************************************************************" << endl;
	signal(SIGALRM, MyAlarm);
//	VECTOR_TESTS();
//	ALGORITHM_TESTS();
	MAP_TESTS();
	leaks_test();
}

void VECTOR_TESTS() {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                              VECTOR                                   |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time"); cout << endl;

	run_vector_unit_test<int>("constructors", constructor_test, constructor_test);
	run_vector_unit_test<int>("iterator operations", iterator_test, iterator_test);
	run_vector_unit_test<int>("push_back()", push_back_test, push_back_test);
	run_vector_unit_test<int>("assign overload", assign_test, assign_test);
	run_vector_unit_test<int>("reserve()", reserve_test, reserve_test);
	run_vector_unit_test<int>("insert(value)", insert_test_1, insert_test_1);
	run_vector_unit_test<int>("insert(iterators)", insert_test_2, insert_test_2);
	run_vector_unit_test<int>("insert(more iterators)", insert_test_3, insert_test_3);
	run_vector_unit_test<int>("erase(pos)", erase_test_1, erase_test_1);
	run_vector_unit_test<int>("erase(iterators)", erase_test_2, erase_test_2);
	run_vector_unit_test<int>("operator[]", operator1_test, operator1_test);
	run_vector_unit_test<int>("at()", at_test, at_test);
	run_vector_unit_test<int>("front()", front_test, front_test);
	run_vector_unit_test<int>("back()", back_test, back_test);
	run_vector_unit_test<int>("data()", data_test, data_test);
	run_vector_unit_test<int>("begin()", begin_test, begin_test);
	run_vector_unit_test<int>("rbegin()", rbegin_test, rbegin_test);
	run_vector_unit_test<int>("end()", end_test, end_test);
	run_vector_unit_test<int>("rend()", rend_test, rend_test);
	run_vector_unit_test<int>("empty()", empty_test, empty_test);
	run_vector_unit_test<int>("size()", size_test, size_test);
	run_vector_unit_test<int>("capacity()", capacity_test, capacity_test);
	run_vector_unit_test<int>("max_size()", maxsize_test, maxsize_test);
	run_vector_unit_test<int>("pop_back()", pop_back_test, pop_back_test);
	run_vector_unit_test<int>("resize()", resize_test, resize_test);
	run_vector_unit_test<int>("clear()", clear_test, clear_test);
	run_vector_unit_test<int>("swap()", swap_test, swap_test);
	run_bool_unit_test("operator ==", operator_equal_test);
	run_bool_unit_test("operator !=", operator_not_equal_test);
	run_bool_unit_test("operator >=", operator_more_equal_test);
	run_bool_unit_test("operator <=", operator_less_equal_test);
	run_bool_unit_test("operator >", operator_more_test);
	run_bool_unit_test("operator <", operator_less_test);
}

void ALGORITHM_TESTS() {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                              ALGORITHMS                              |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	run_bool_unit_test("is_integral", is_integral_test_);
	run_bool_unit_test("enable_if", enable_if_test_);
	run_bool_unit_test("equal", equal_test);
	run_bool_unit_test("lexicographical", lexicographical_test);
}

void MAP_TESTS() {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                                  MAP                                 |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	run_map_unit_test<int, int>("constructor(InputIt)", copy_constructor_test, copy_constructor_test);
	run_map_unit_test<int, int>("assign overload (=)", assign_overload_test, assign_overload_test);
	run_map_unit_test<int, int>("iterators", iterators_test, iterators_test);
	run_map_unit_test<int, int>("reverse iterators", reverse_iterators_test, reverse_iterators_test);
	run_map_unit_test<int, int>("Compare class", comparator_test, comparator_test);
	run_map_unit_test<int, int>("insert(pair)", insert_test, insert_test);
	run_map_unit_test<int, int>("insert(InputIt)", insert_test_2, insert_test_2);
	run_map_unit_test<int, int>("insert(hint)", insert_test_3, insert_test_3);
	run_map_unit_test<int, int>("at()", at_test, at_test);
	run_map_unit_test<int, int>("operator[]", operator_sq_test, operator_sq_test);
	run_map_unit_test<int, int>("empty()", empty_test, empty_test);
	run_map_unit_test<int, int>("size()", size_test, size_test);
	run_map_unit_test<int, int>("max_size()", max_size_test, max_size_test);
	run_map_unit_test<int, int>("clear()", clear_test, clear_test);
	run_map_unit_test<int, int>("erase(key)", erase_test_1, erase_test_1);
	run_map_unit_test<int, int>("erase(pos)", erase_test_2, erase_test_2);
	run_map_unit_test<int, int>("erase(InputIt)", erase_test_3, erase_test_3);
	run_map_unit_test<int, int>("swap()", swap_test, swap_test);
	run_map_unit_test<int, int>("count()", count_test, count_test);
	run_map_unit_test<int, int>("find()", find_test, find_test);
	run_map_unit_test<int, int>("lower bound", lower_bound_test, lower_bound_test);
	run_map_unit_test<int, int>("upper bound", upper_bound_test, upper_bound_test);
	run_map_unit_test<int, int>("equal range", equal_range_test, equal_range_test);
	run_map_unit_test<int, int>("key comp()", key_comp_test, key_comp_test);
	run_bool_unit_test("operator ==", map_equal_test);
	run_bool_unit_test("operator !=", map_not_equal_test);
	run_bool_unit_test("operator <", map_less_than_test);
	run_bool_unit_test("operator >", map_more_than_test);
	run_bool_unit_test("operator <=", map_less_or_equal_test);
	run_bool_unit_test("operator >=", map_more_or_equal_test);
}