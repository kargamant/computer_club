#include <Parser/Parser.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::ifstream fs{argv[1]};

    std::string line;
    fs >> line;
    std::cout << "line: " << line << std::endl;

    return 0;
}