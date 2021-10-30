cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(./)

file(GLOB ft_containers_unit_tests CONFIGURE_DEPENDS "*.hpp" "*.cpp" "*.ipp" "*.c")

add_executable( ft_containers
                main.cpp
        ft_containers_tests/test_functions.ipp
        ft_containers_tests/start_tests.hpp
                Stack.hpp
                Map.hpp
                Vector.hpp
                Iterator.hpp
        Utility.hpp Node.hpp ft_containers_tests/lib.hpp Set.hpp ft_containers_unit_tests/sources/system/system.ipp ft_containers_unit_tests/sources/system/map_run.cpp ft_containers_unit_tests/sources/map_tests/map_operator==.cpp ft_containers_unit_tests/sources/map_tests/map_operator!=.cpp ft_containers_unit_tests/sources/map_tests/map_operator>.cpp ft_containers_unit_tests/sources/map_tests/map_operator<.cpp ft_containers_unit_tests/sources/map_tests/map_operator<=.cpp ft_containers_unit_tests/sources/map_tests/map_operator>=.cpp ft_containers_unit_tests/sources/system/vector_run.cpp)