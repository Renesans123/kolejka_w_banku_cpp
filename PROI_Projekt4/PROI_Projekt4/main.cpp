#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "mainHeader.h"
using namespace std;

int main(int argc, char* argv[])
{
    srand((unsigned)time(NULL));

    //                      TESTS 

    //int result = Catch::Session().run(argc, argv);
    //return result;

    //                  END TESTS

	//Bank b = Bank(1, 1);
	//b.simulate();
    runSimulation(7, 77);
    return 0;
}
