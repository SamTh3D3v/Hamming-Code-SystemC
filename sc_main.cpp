#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"
#include "SYSTEM.h"


SYSTEMH *sysh=NULL;
int sc_main(int argc, char *argv[])
{
    cout << " The Simulation Started"<< endl;
	sysh=new SYSTEMH("sysh");
    sc_start();     //start the simulation
	cout <<" The Simulation Ended "<<endl;
	return 0;
}
