#include <systemc.h>


SC_MODULE(Corrector)
{
	//Ports
	sc_in < sc_uint<15> > datain;
	sc_in < sc_uint<4> > syndin;
	sc_out < sc_uint<15> > dout;

	//peocessus principal

	void correct();
	//constructeur
	SC_CTOR(Corrector){
	SC_METHOD(correct);
	sensitive << datain << syndin;
	}
};
