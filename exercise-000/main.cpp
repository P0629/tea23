#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {} in version {}!\n", tea::PROJECT_NAME, tea::PROJECT_VER);
/*Teil 0*/
    for (int i=0; i< argc; i++) {
        fmt::println("argc: {}, argument {} (Adresse: {})", i, argv[i], fmt::ptr(argv[i]));
    }
    /*Teil 1*/
    int foo = 10;
    int* ptr = &foo;
    *ptr = 42;
    fmt::println("int foo = 10;");
    fmt::println("int* ptr = &foo;");
    fmt::println("Adresse von foo: {} Adresse im pointer ptr: {}", fmt::ptr(&foo), fmt::ptr(ptr));
    int bar = 4711;
    ptr = &bar;
    *ptr = foo;     /*was steht in bar?*/
    fmt::print("bar = {}", bar);

    /*Teil 2*/
    

    return 0; /* exit gracefully*/
}
