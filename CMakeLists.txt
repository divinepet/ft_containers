cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(./)

file(GLOB ft_containers_unit_tests CONFIGURE_DEPENDS "*.hpp" "*.cpp" "*.ipp" "*.c")

add_executable( ft_containers
                main.cpp
                Stack.hpp
                Map.hpp
                Vector.hpp
                Iterator.hpp
        Utility.hpp Node.hpp Set.hpp ft_containers_unit_tests/sources/system/system_methods.ipp ft_containers_unit_tests/sources/system/run_map.cpp ft_containers_unit_tests/sources/map_tests/operator==.cpp ft_containers_unit_tests/sources/map_tests/operator!=.cpp ft_containers_unit_tests/sources/map_tests/operator>.cpp ft_containers_unit_tests/sources/map_tests/operator<.cpp ft_containers_unit_tests/sources/map_tests/operator<=.cpp ft_containers_unit_tests/sources/map_tests/operator>=.cpp ft_containers_unit_tests/sources/system/run_vector.cpp ft_containers_unit_tests/sources/utilities_tests/is_integral.cpp ft_containers_unit_tests/sources/system/run_utilities.cpp ft_containers_unit_tests/sources/utilities_tests/equal.cpp ft_containers_unit_tests/sources/utilities_tests/enable_if.cpp ft_containers_unit_tests/sources/utilities_tests/lexicographical.cpp ft_containers_unit_tests/sources/system/run_set.cpp ft_containers_unit_tests/sources/stack_tests/constructor.cpp ft_containers_unit_tests/sources/system/run_stack.cpp "ft_containers_unit_tests/sources/stack_tests/top().cpp" "ft_containers_unit_tests/sources/stack_tests/size().cpp" "ft_containers_unit_tests/sources/stack_tests/pop().cpp" "ft_containers_unit_tests/sources/stack_tests/empty().cpp" "ft_containers_unit_tests/sources/stack_tests/push().cpp")