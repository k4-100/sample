#include <iostream>
//std::ofstream
#include <fstream>
// std::to_string()
#include <string>
// std::mt19937, std::uniform_int_distribution
#include <random>
// std::fixed, std::time()?, std::fixed()?
#include <iomanip>

/// @param count amount of values to generate
/// @param maxDiceValue maximal value for dice's range
void writeSample( const uint16_t count = 10, const uint16_t maxDiceValue = 20 ){
    // writes data into a file (creates it, if necessary)
    std::ofstream writer( "sample.txt" );

    // random number generator
    std::mt19937 generator;
    generator.seed( std::time( 0 ) );
    
    // uniform limiting range of possible values
    std::uniform_real_distribution< float > dice( 0, maxDiceValue >  INT16_MAX ? INT16_MAX  : maxDiceValue );

    // buffer for storing loop output
    std::stringstream buffer;

    // maximal index ( can be no bigger than 365 )
    const uint16_t maxIndex =  count > 365 
        ? 365 
        : count;

    for (uint16_t i = 0; i < maxIndex; i++)
    {
        float generatedValue =  ( dice( generator ) );

        // stream data into buffer, while also ensuring that decimal places will be displayed with decimal place
        // and that the precision will be up to 1 decimal place
        buffer <<  std::fixed << std::setprecision( 1 ) <<  generatedValue  <<  '\n';
    }

    writer << buffer.str();
}


int main( int argc, char* argv[] )
{   

    switch( argc ){
        case 1:
            writeSample();
        break;
        case 2:
            writeSample( atoi( argv[1] ) );
        break;
        case 3:
            writeSample( atoi( argv[1] ),  atoi( argv[2] ) );
        break;
        default: 
            std::cout<< "wrong arguments\n";
        break;
    }
}