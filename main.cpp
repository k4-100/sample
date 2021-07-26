#include <iostream>
//std::ofstream
#include <fstream>
// to_string()
#include <string>

int main()
{
    std::ofstream writer("sample.txt");

    // buffer for storing loop output
    std::string buffer = "";
    for (uint8_t i = '\000'; i < 200; i++)
    {
        buffer += std::to_string(i) + '\n';
    }

    std::cout << buffer << '\n';
}