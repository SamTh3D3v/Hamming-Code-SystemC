#include "regDefaillant.h"

void shiftD::shifterD()
{
	 sc_uint <11> tmp;

	  tmp= (din.read()+1);

	dout.write(tmp); // version defaillante
}

