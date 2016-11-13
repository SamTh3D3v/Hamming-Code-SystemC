#include "reg.h"

void shift::shifter()
{
	sc_uint <11> tmp;
	tmp= (din.read());

	dout.write(tmp); //non defaillante
}
