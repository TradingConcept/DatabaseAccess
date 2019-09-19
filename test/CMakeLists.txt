find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories("${PROJECT_SOURCE_DIR}/include")

set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/DatabaseAccessTest.cpp)
set(TEST_LIBS DatabaseAccessLib)

add_executable(test_main ${TEST_SOURCES})
target_link_libraries(
    test_main 
    mariadb
    ${TEST_LIBS} 
    ${Boost_LIBRARIES})
add_test(DatabaseAccessTest test_main COMMAND test_main)
