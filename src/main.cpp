#include <iostream>
#include <thread>
#include <future>

#include "DatabaseAccess.h"
#include "Player.hpp"


u_long factorial( int N )
{    
    u_long result = 1;
    for( int i = N; i > 1 ; i-- )
    {
        result *= i ;
    }

    std::cout << N << "! = " << result << std::endl ;
    return result ;

}


int main(int argc, char *argv[])
{
    int N = atoi( argc > 1 ? argv[1] : "999" ) ;

    // Biker p0( "Hugo") ;
    // Runner p1( "Paco") ;
    // Runner p2( "Luis") ;

    // p0.PrintName();
    // p1.PrintName();
    // p2.PrintName();

    // return 0 ;

    // ------------------------------------------------------------------------------------------------------------------------------
    // factorial( N ) ;

    // // ------------------------------------------------------------------------------------------------------------------------------
    // std::thread t1( factorial, N ) ;
    // t1.join();

    // // ------------------------------------------------------------------------------------------------------------------------------
    // auto fu1 = std::async( std::launch::async, factorial, N );
    // auto fu2 = std::async( std::launch::async, factorial, N );
    // auto fu3 = std::async( std::launch::async, factorial, N );
        
    // return 0 ;

    DatabaseAccessLib::Run();

    std::cout << "Finalizando Servicio..." << std::endl;

    return 0;
}
 