cmake_minimum_required(VERSION 3.30)
project(Jalilan)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -g")

find_package(libssh CONFIG REQUIRED PATHS /usr/local/Cellar/libssh/0.11.1/lib/cmake/libssh)

add_executable(Jalilan main.cpp
        Target.hh
        Progress.hh
        Jalilan.hh
        Log.hh
        IpRange.hh
        GetLineLim.hh
        Detection.hh
        Credentials.hh
        Compat.hh
        AttackFlood.hh
        Support.hh
        Target.cc
        Log.cc)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}
        Support.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE ssh)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

