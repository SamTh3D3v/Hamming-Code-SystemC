#include <systemc.h>
#include "HCGenerator.h"
#include "SynGenerator.h"

//ce registre permet d'envoyer et recevoire des mot code en Hamming



SC_MODULE(HamReg)
{
	HCGen *hgen;
	SynGen *sgen;
	Corrector *corr;

	//Ports
	sc_in < sc_logic > clk;
	sc_in < sc_uint<15> > coded_din;
	sc_out < sc_uint<15> > coded_dout;

	//les données a codé
	sc_in < sc_uint<11> > din;
    sc_out < sc_uint<11> > dout;

    //signal de connection des modules
    sc_signal < sc_uint <4> > syndSig;

	//processus principal

	void coder();
	void decoder();

	//constructeur
	SC_CTOR(HamReg){
		hgen=new HCGen("hgen");
		hgen->din( din );
		hgen->dout( coded_dout );

         //pour le calcule du syndrome
		sgen=new SynGen("sgen");
		sgen->din( coded_din );
        sgen->dout( syndSig );


		corr=new Corrector("corr");
		corr->datain( din );
		corr->syndin( syndSig );
		corr->dout( dout );

	sensitive << coded_din << din ;
	}
	~HamReg(){
     delete hgen;
     delete sgen;
     delete corr;
	}
};
