#pragma once

#include <vector>
#include <fstream>
#include <execinfo.h>
#include <iomanip>
#include <sys/time.h>
#include <sstream>
#include <unistd.h>
#include <iostream>
void vector_tests();
void algorithm_tests();
void map_tests();

/*******************************************************************************************************************/
/*							YOUR TEMPLATE NAMES							            							   */
#include 					"../Utility.hpp"
#include 					"../Vector.hpp"
#include 					"../Map.hpp"
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define _exec_name 			"app"
/*******************************************************************************************************************/

#include "functions.hpp"

void start_tests() {
	cout << "************************************************************************" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                    ft_containers TESTS by @elaronda                  *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "************************************************************************" << endl;
//	vector_tests();
//	algorithm_tests();
	map_tests();
	leaks_test();
}

void vector_tests() {
	std::vector<int> vector;
	ft::Vector<int> my_vector;
	time_t t1;
	time_t t2;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                              VECTOR                                   |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	printElement("Function");
	printElement("Result");
	printElement("ft time       std time");
	cout << endl;


	// comment to turn off some test
	printElement("constructors");(constructor_test(vector) == constructor_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("push_back(1000000)");(push_back_test(vector) == push_back_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("assign(all)");(assign_test(vector) == assign_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("reserve()");(reserve_test(vector) == reserve_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("insert(value)");(insert_test_1(vector) == insert_test_1(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("insert(iterators)");(insert_test_2(vector) == insert_test_2(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("insert(iterators 2)");(insert_test_3(vector) == insert_test_3(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("erase(pos)");(erase_test_1(vector) == erase_test_1(my_vector)) ? printElement("OK") : printElement("FAILED"); t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("erase(iterators)");(erase_test_2(vector) == erase_test_2(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator[]");(operator1_test(vector) == operator1_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("at(354000)");(at_test(vector) == at_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("front()");(front_test(vector) == front_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("back()");(back_test(vector) == back_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("data()");(data_test(vector) == data_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("begin()");(begin_test(vector) == begin_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("rbegin()");(rbegin_test(vector) == rbegin_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("end()");(end_test(vector) == end_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("rend()");(rend_test(vector) == rend_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("empty()");(empty_test(vector) == empty_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("size()");(size_test(vector) == size_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("capacity()");(capacity_test(vector) == capacity_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("max_size()");(maxsize_test(vector) == maxsize_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("pop_back()");(pop_back_test(vector) == pop_back_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("resize()");(resize_test(vector) == resize_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("clear()");(clear_test(vector) == clear_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("swap()");(swap_test(vector) == swap_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator ==");(operator_equal_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator !=");(operator_not_equal_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator >=");(operator_more_equal_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator <=");(operator_less_equal_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator >");(operator_more_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator <");(operator_less_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("Iterator operations");(iterator_test(vector) == iterator_test(my_vector)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
}

void algorithm_tests() {
	time_t t1;
	time_t t2;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                              ALGORITHMS                              |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	printElement("is_integral");(is_integral_test_() == 0) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("enable_if");(enable_if_test_() == 0) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("equal");(equal_test() == 0) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("lexicographical");(lexicographical_test()) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
}

void map_tests() {
	std::map<int, int> map;
	ft::Map<int, int> my_map;
	time_t t1;
	time_t t2;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "|                                  MAP                                 |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	printElement("Function");
	printElement("Result");
	printElement("ft time       std time");
	cout << endl;

	printElement("constructor(InputIt)");(copy_constructor_test(map) == copy_constructor_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("assign overload (=)");(assign_overload_test(map) == assign_overload_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("iterators");(iterators_test(map) == iterators_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("reverse iterators");(reverse_iterators_test(map) == reverse_iterators_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("compare class");(comparator_test(map) == comparator_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("insert()");(insert_test(map) == insert_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("insert(InputIt)");(insert_test_2(map) == insert_test_2(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("at()");(at_test(map) == at_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("operator[]");(operator_sq_test(map) == operator_sq_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("empty()");(empty_test(map) == empty_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("size()");(size_test(map) == size_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("max_size()");(max_size_test(map) == max_size_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("clear()");(clear_test(map) == clear_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("erase(key)");(erase_test_1(map) == erase_test_1(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("erase(pos)");(erase_test_2(map) == erase_test_2(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("erase(InputIt)");(erase_test_3(map) == erase_test_3(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("lower bound");(lower_bound_test(map) == lower_bound_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("upper bound");(upper_bound_test(map) == upper_bound_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
	printElement("equal range");(equal_range_test(map) == equal_range_test(my_map)) ? printElement("OK") : printElement("FAILED");t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);cout << endl;
}