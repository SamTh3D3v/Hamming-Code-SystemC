#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"
#include "SYSTEM.h"


SYSTEMH *sysh=NULL;
int sc_main(int argc, char *argv[])
{
    cout << " Simulation Demarrer "<< endl;
	sysh=new SYSTEMH("sysh");
    sc_start();     //pour demarrer la simulation
	cout <<" Simulation Terminer "<<endl;
	return 0;
}
