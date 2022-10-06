cmake_minimum_required(VERSION 3.5)

project(search_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(search_engine main.cpp)

add_library(MyLibrary STATIC
    converterjson.h converterjson.cpp
    invertedindex.h invertedindex.cpp
    searchserver.h searchserver.cpp
    nlohmann/json.hpp
    config.json
    requests.json
)


#target_link_libraries(search_engine PUBLIC nlohmann_json::nlohmann_json)

#target_link_libraries(MyLibrary PUBLIC search_engine)

#add_executable(main2 main2.c)
#target_link_libraries(main2 obj2)

target_link_libraries(search_engine  PUBLIC MyLibrary)

