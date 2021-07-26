#include <iostream>
//std::ofstream
#include <fstream>
// std::to_string()
#include <string>
// std::mt19937, std::uniform_int_distribution
#include <random>
// std::setprecision()
#include <iomanip>



int main()
{
    // writes data into a file (creates it, if necessary)
    std::ofstream writer( "sample.txt" );

    // random number generator
    std::mt19937 generator;
    generator.seed( std::time( 0 ) );

    // uniform limiting range of possible values
    std::uniform_real_distribution< float > dice( 0, 20 );

    // buffer for storing loop output
    std::stringstream buffer;
    
    // maximal index ( can be no bigger than 365 )
    const uint16_t maxIndex = uint16_t( 10 % 366);

    for (uint16_t i = 0; i < maxIndex; i++)
    {
        float generatedValue =  ( dice( generator ) );

        // stream data into buffer, while also ensuring that decimal places will be displayed with decimal place
        // and that the precision will be up to 1 decimal place
        buffer <<  std::fixed << std::setprecision( 1 ) <<  generatedValue  <<  '\n';
    }

    writer << buffer.str();
}