/*
    . The example code compiles and links with visual C++
    . It doesn't work with g++ (yet??)
    . The example code compiles fine with clang 18
*/
#include <fmt/format.h>
// import <iostream>;
import math;

int main()
{
    //Add 10 to 20 and print the result using the math module
    fmt::println("10 + 20 = {}", math::add(10, 20) );
    // std::cout << "10 + 20 = " << math::add(10, 20) << std::endl;
}