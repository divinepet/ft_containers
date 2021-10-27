#ifndef UNIT_TESTS_HPP
# define UNIT_TESTS_HPP

#include <vector>
#include <map>
#include <fstream>
#include <execinfo.h>
#include <iomanip>
#include <sys/time.h>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include <csetjmp>

/*******************************************************************************************************************/
/*							YOUR TEMPLATE NAMES							            							   */
#include 					"../Utility.hpp"
#include 					"../Vector.hpp"
#include 					"../Map.hpp"
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_map	 			ft::Map
#define	_vector 			ft::Vector
#define _exec_name 			"ap"
/*******************************************************************************************************************/

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;
pid_t pid;
volatile static int timeout_flag = 0;

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string RESET = "\033[0m";

using std::string;
using std::cout;
using std::endl;

void VECTOR_TESTS();
void ALGORITHM_TESTS();
void MAP_TESTS();
#include "test_functions.ipp"

#endif