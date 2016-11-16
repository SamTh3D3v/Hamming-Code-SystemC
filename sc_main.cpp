#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"
#include "SYSTEM.h"


SYSTEMH *sysh=NULL;

int sc_main(int argc, char* argv)
{
	sysh=new SYSTEMH("sysh");
	sc_start();
	return 0;
}
