#ifndef SYNGEN_
#define SYNGEN_

#include <systemc.h>


SC_MODULE(SynGen)
{
	//Ports
	sc_in < sc_logic > clk;
	sc_in < sc_uint<15> > din;
	sc_out < sc_uint<4> > dout;

	//peocessus principal

	void calculate();

	//constructeur
	SC_CTOR(SynGen){
	SC_METHOD(calculate);
	sensitive << din;
	}
};


#endif
