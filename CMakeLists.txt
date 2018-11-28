cmake_minimum_required(VERSION 3.12)
project(USACO)

set(CMAKE_CXX_STANDARD 14)

add_executable(USACO
        gold/feb08/hotel/hotel.cpp
        gold/jan13/seating/seating.cpp
        gold/OPEN11/mowlawn/mowlawn.cpp
        Other/mou/mou.cpp
        Other/mou2/mou2.cpp
        silver/nov09/xoinc/xoinc.cpp)
