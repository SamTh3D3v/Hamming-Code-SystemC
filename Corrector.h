#ifndef CORR_
#define CORR_
#include <systemc.h>


SC_MODULE(Corrector)
{
	//Ports
	sc_in < sc_uint<15> > datain;
	sc_in < sc_uint<4> > syndin;
	sc_out < sc_uint<11> > dout;
	sc_in < bool > clk;

	sc_in < bool > codedin_vld;
	sc_out < bool > codedin_rdy;
	sc_out < bool > dout_vld;
	sc_in < bool > dout_rdy;

	//peocessus principal

	void correct();
	//constructeur
	SC_CTOR(Corrector){
	SC_CTHREAD(correct,clk.pos());
	sensitive << datain << syndin;
	//sensitive << clk.pos();

	}
};

#endif
