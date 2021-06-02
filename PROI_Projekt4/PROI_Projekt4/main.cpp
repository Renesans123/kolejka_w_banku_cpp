#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"
#include "mainHeader.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand((unsigned)time(NULL));

    //                      TESTS 

    //int result = Catch::Session().run(argc, argv);
    //return result;

    //                  END TESTS
//	Product p = Product(new_user_help, 10, "");
//	Client c = Client("", "", "Passport", "12345678901", 1111, "1234", p);
//	cout<<c;
//	c.reduceProductTime();
//	cout<<c;

	Bank b = Bank(7, 111);
	b.simulate(1);
    return 0;
}
