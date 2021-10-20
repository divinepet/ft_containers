#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"

std::string ft_exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	} catch (...) { pclose(pipe); throw; }
	pclose(pipe);
	return result;
}

std::string ft_get_leak_string(std::string s) {
	std::string tmp;
	int idx = s.find("total leaked bytes");
	for (; s[idx] != '\n' ; --idx) {}
	int edx = idx + 1;
	for (; s[edx] != '\n' ; ++edx) {}
	return s.substr(++idx, edx - 101);
}

void ft_leaks() {
	string a = "leaks ";
	a += _exec_name;
	usleep(50);
	string s = ft_get_leak_string(ft_exec(a.c_str()));
	cout << YELLOW + s.substr(0, s.length() - 2) + RESET << endl;
}










int main(int argc, char **argv) {
//	start_tests();
//	ft_leaks();
}
