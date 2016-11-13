#include <systemc.h>


SC_MODULE(HCGen)
{
	//Ports
	sc_in < sc_logic > clk;
	sc_in < sc_uint<11> > din;
	sc_out < sc_uint<15> > dout;

	//peocessus principal

	void generate();

	//constructeur
	SC_CTOR(HCGen){
	SC_METHOD(generate);
	sensitive << din;
	}
};
