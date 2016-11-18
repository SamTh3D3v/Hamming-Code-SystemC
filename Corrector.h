#ifndef CORR_       //pour eviter le probleme d'inclusion infinie
#define CORR_
#include <systemc.h>


//cet circuit permet de corriger "datain" en se basant le syndrome "syndin"
//le mot est par la suit decodé en un mot de 11 bits

SC_MODULE(Corrector)
{
	//Les Portes

	sc_in < sc_uint<15> > datain;
	sc_in < sc_uint<4> > syndin;
	sc_out < sc_uint<11> > dout;
	sc_in < bool > clk;


	//les signaux de hand shake
	sc_in < bool > codedin_vld;   //pour datain
	sc_out < bool > codedin_rdy;

	sc_out < bool > dout_vld;  //pour dout
	sc_in < bool > dout_rdy;

	//processus principal

	void correct();
	//constructeur
	SC_CTOR(Corrector){
		SC_CTHREAD(correct,clk.pos());
		sensitive << datain << syndin;
	}
};

#endif
