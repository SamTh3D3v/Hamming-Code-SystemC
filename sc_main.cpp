#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"
#include "SYSTEM.h"


SYSTEM *system=NULL;

int sc_main(int argc, char* argv)
{
	system=new SYSTEM("system");
	sc_start();
	return 0;
}
