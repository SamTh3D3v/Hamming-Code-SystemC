#include "systemc.h"


SC_MODULE (testbenchreg){
	//Module Declaration Part
	sc_out<sc_logic> clk;
	sc_out< sc_uint<11> > din;
	sc_in< sc_uint<11> > dout;

	void clkInput();
	void dinInput();
	void display();

	SC_CTOR(testbenchreg){
		SC_THREAD(clkInput);

		SC_THREAD(dinInput);
		SC_METHOD(display)
		sensitive << din <<clk;
	}
};
