#ifndef HCGEN_    //pour eviter le probleme d'inclusion infinie
#define HCGEN_
#include <systemc.h>

//Cet circuit permet de generer un mot de code de 15 bits
//a partir d'un mot de 11 bits

SC_MODULE(HCGen)
{
	//Les portes
	sc_in < bool > clk;
	sc_in < sc_uint<11> > din;
	sc_out < sc_uint<15> > dout;


	//les signaux de hand shake
	sc_in < bool > din_vld;        //pour din
	sc_out < bool > din_rdy;

	sc_out < bool > codedout_vld;    //pour dout
	sc_in < bool > codedout_rdy;

	//peocessus principal

	void generate();

	//le constructeur
	SC_CTOR(HCGen){
	SC_CTHREAD(generate,clk.pos());
	sensitive << din;
	sensitive << din_vld;
	sensitive << clk.pos();
	}
};

#endif
