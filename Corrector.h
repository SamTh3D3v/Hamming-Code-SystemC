#ifndef CORR_
#define CORR_
#include <systemc.h>

/*This circuit corrects "datain" using the already calculated syndrome "syndin"
 The word is then decoded into its original 11 bits. */

SC_MODULE(Corrector)
{
	// Ports

	sc_in < sc_uint<15> > datain;
	sc_in < sc_uint<4> > syndin;
	sc_out < sc_uint<11> > dout;
	sc_in < bool > clk;


	// hand shake signals
	sc_in < bool > codedin_vld;   //for datain
	sc_out < bool > codedin_rdy;

	sc_out < bool > dout_vld;  //for dout
	sc_in < bool > dout_rdy;


	void correct();
	SC_CTOR(Corrector){
		SC_CTHREAD(correct,clk.pos());
		sensitive << datain << syndin;
	}
};

#endif
