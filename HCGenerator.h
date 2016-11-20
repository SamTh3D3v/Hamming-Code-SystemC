#ifndef HCGEN_
#define HCGEN_
#include <systemc.h>


/*this circuit calculate a 15 bits hamming code word from an 11 bits one*/

SC_MODULE(HCGen)
{
	//Ports
	sc_in < bool > clk;
	sc_in < sc_uint<11> > din;
	sc_out < sc_uint<15> > dout;


	//Handshakes signals
	sc_in < bool > din_vld;
	sc_out < bool > din_rdy;

	sc_out < bool > codedout_vld;
	sc_in < bool > codedout_rdy;


	void generate();


	SC_CTOR(HCGen){
		SC_CTHREAD(generate,clk.pos());
		sensitive << din;
		sensitive << din_vld;
		sensitive << clk.pos();
	}
};

#endif
