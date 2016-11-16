#ifndef TESTBENCH_
#define TESTBENCH_

#include <systemc.h>


SC_MODULE (tbreg){

	sc_in < bool > clk;
	sc_out < sc_uint<15> > coded_din;
	sc_in < sc_uint<15> > coded_dout;

	sc_out < sc_uint<11> > din;
    sc_in < sc_uint<11> > dout;

    //les signaux de handshakes
    sc_out < bool > din_vld;
    sc_in < bool > din_rdy;

    sc_out < bool > codedin_vld;
    sc_in < bool > codedin_rdy;

    sc_in < bool > codedout_vld;
    sc_out < bool > codedout_rdy;

    sc_in < bool > dout_vld;
    sc_out < bool > dout_rdy;


	void send();
	void receive();

	SC_CTOR(tbreg){
		SC_CTHREAD(send,clk);
		SC_CTHREAD(receive,clk);
	}
};


#endif
