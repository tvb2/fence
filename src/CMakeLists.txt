cmake_minimum_required(VERSION 3.0.0)
project(fence VERSION 0.1.0)

# copy configuration files into build directory
if (WIN32)
    configure_file(../config_win.json config.json COPYONLY)
else()
    configure_file(../config_lin.json config.json COPYONLY) #unix
endif(WIN32)

add_executable(fence 
                main.cpp
                ${INCLUDE_DIR}/converterjson.h converterjson.cpp
                ${INCLUDE_DIR}/vect.h vect.cpp
                
                )

target_include_directories(fence PUBLIC ${INCLUDE_DIR})

target_link_libraries(fence PRIVATE nlohmann_json::nlohmann_json)