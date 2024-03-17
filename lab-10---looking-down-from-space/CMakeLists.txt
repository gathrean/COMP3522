cmake_minimum_required(VERSION 3.12)
project(LabSpaceTemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabSpaceTemplate main.cpp consumer.hpp city_info_queue.hpp city_info.hpp producer.hpp location.hpp iss_data_request.hpp)
