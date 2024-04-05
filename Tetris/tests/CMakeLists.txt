project(tests)

set(SOURCES
   catch_amalgamated.cpp
   catch_amalgamated.hpp
   main.cpp
)
add_executable(aba_tests ${SOURCES})
set_target_properties(aba_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(aba_tests metier)
