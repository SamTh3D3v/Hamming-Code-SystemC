#ifndef SYNGEN_
#define SYNGEN_

#include <systemc.h>


/*this circuit is for calculating the syndrome for a given word
  the syndrome (4 bits )== parity matrix (for 15, 11) * the code word (15 bits)*/

SC_MODULE(SynGen)
{
	//Ports
	sc_in < bool > clk;
	sc_in < sc_uint<15> > din;    //a code word
	sc_out < sc_uint<4> > dout;   //the syndrome


	void calculate();

	SC_CTOR(SynGen){
		SC_METHOD(calculate);
		sensitive << din;
	}
};


#endif
