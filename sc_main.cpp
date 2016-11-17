#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"
#include "SYSTEM.h"


SYSTEMH *sysh=NULL;
int sc_main(int argc, char *argv[])
{
    cout << " start simulation \n"<< endl;
	sysh=new SYSTEMH("sysh");
    sc_start();
	cout <<"Simulation ended \n"<<endl;
	return 0;
}
