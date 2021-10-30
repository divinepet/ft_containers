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
#include <unistd.h>
#include <fcntl.h>
#include "../../YourNames.hpp"

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string RESET = "\033[0m";

using std::string;
using std::cout;
using std::endl;

#define _CXX "/usr/bin/clang++"
#define _CXX_FLAGS "-Wall -Wextra -Werror"
#define _EXEC_NAME "test1"
#define _ALARM_TIMEOUT 7

#include "system.ipp"
#include "execute.ipp"

#endif