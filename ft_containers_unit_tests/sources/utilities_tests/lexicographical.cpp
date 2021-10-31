#include "../system/lib.hpp"

bool lexicographical_test() {
	std::vector<int> result, result2;
	std::vector<char> v1, v2;
	_vector<char> b1, b2;
	v1.assign(50000000, 'f');
	v1.push_back('e');
	v2.assign(50000000, 'f');
	v2.push_back('e');
	b1.assign(50000000, 'f');
	b1.push_back('e');
	b2.assign(50000000, 'f');
	b2.push_back('e');
	g_start1 = timer();
	result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	g_end1 = timer();
	g_start2 = timer();
	result2.push_back(_lexicographical(b1.begin(), b1.end(), b2.begin(), b2.end()));
	g_end2 = timer();
	return result == result2;
}

int main() {
	run_bool_unit_test("lexicographical", lexicographical_test);
}