cmake_minimum_required(VERSION 3.21)
project(ArgoVM)

add_compile_options(-Wall -Wextra -pedantic)

set (CMAKE_C_FLAGS "-fsanitize=address")

# Common

list(APPEND argo_src 
    src/diagnostic/snapshots.c 
    src/internal/cli.c 
    src/internal/options.c 
    src/internal/loop.c
    src/internal/operations.c 
    src/internal/bytecode.c 
    src/internal/parser.c
    src/internal/stack.c 
    src/internal/vm.c 
)

list(APPEND argo_test_src 
    test/core/test-engine.c
    test/core/test-decoder.c
)

list(APPEND argo_inc_dir
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/argtable3 
)

list(APPEND argo_link_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/argtable3/argtable3.c 
    m
)

# Argo

add_executable(argo src/main.c ${argo_src})

target_include_directories(argo PRIVATE ${argo_inc_dir})
target_link_libraries(argo PRIVATE ${argo_link_lib})

install(TARGETS argo DESTINATION ${CMAKE_INSTALL_PREFIX})

# Test

list(APPEND argo_inc_dir ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/munit src/core)
list(APPEND argo_link_lib ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/munit/munit.c)

add_executable(argo-test-vm test/main.c ${argo_test_src} ${argo_src})

target_include_directories(argo-test-vm PRIVATE ${argo_inc_dir})
target_link_libraries(argo-test-vm PRIVATE ${argo_link_lib})
