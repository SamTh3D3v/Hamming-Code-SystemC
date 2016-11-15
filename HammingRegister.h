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

    //les signaux de handshake
    sc_in < bool > din_vld;
    sc_out < bool > din_rdy;

    sc_in < bool > codedin_vld;
    sc_out < bool > codedin_rdy;

    sc_out < bool > codedout_vld;
    sc_in < bool > codedout_rdy;

    sc_out < bool > dout_vld;
    sc_in < bool > dout_rdy;

    void ham_main_din();
    void ham_main_codedin();

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

		SC_METHOD(ham_main_din);
		SC_METHOD(ham_main_codedin);

	sensitive << coded_din << din ;
	}
	~HamReg(){
     delete hgen;
     delete sgen;
     delete corr;
	}
};
