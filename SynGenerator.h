#ifndef SYNGEN_    //pour eviter le probleme d'inclusion infinie
#define SYNGEN_

#include <systemc.h>


//ce module permet de calculer le syndrome d'un mot de donner
//le syndrome (sur 4 bits)= (la matrice de parité (15, 11)) * le mot de code (sur 15 bits)

SC_MODULE(SynGen)
{
	//Les Portes
	sc_in < bool > clk;
	sc_in < sc_uint<15> > din;    //un mot de code
	sc_out < sc_uint<4> > dout;   //le syndrome

	//processus principal

	void calculate();

	//constructeur
	SC_CTOR(SynGen){
		SC_METHOD(calculate);
		sensitive << din;
	}
};


#endif
