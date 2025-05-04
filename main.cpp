#include <Parser/Parser.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <Pipeline.hpp>

int main(int argc, char* argv[])
{
    Pipeline pipe;
    pipe.make_report(argv[1], std::cout);

    return 0;
}