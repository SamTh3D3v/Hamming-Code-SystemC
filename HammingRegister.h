#ifndef HAMMINGREG_    //pour eviter le probleme d'inclusion infinie
#define HAMMINGREG_

#include <systemc.h>
#include "HCGenerator.h"
#include "SynGenerator.h"
#include "Corrector.h"

//ce registre permet d'envoyer et recevoire des mot de code de Hamming


SC_MODULE(HamReg)
{
	HCGen *hgen;  //le circuit qui genere le mot de code
	SynGen *sgen;  //le circuit qui genere le syndrome
	Corrector *corr; //le circuit de correction et de decodage

	//Les Portes
	sc_in < bool > clk;
	sc_in < sc_uint<15> > coded_din;   //mot de code a decoder
	sc_out < sc_uint<15> > coded_dout;  //mot de code generé

	//les données a codées
	sc_in < sc_uint<11> > din;    //mot a coder
    sc_out < sc_uint<11> > dout;   //un mot decodé

    //signal de connection des modules
    sc_signal < sc_uint <4> > syndSig;
    sc_signal< sc_uint <11> > din_sig;
    sc_signal< sc_uint <15> > codeddout_sig;

    //les signaux de handshake
    sc_in < bool > din_vld;
    sc_out < bool > din_rdy;
    sc_out < bool > codedout_vld;
    sc_in < bool > codedout_rdy;


    sc_in < bool > codedin_vld;
    sc_out < bool > codedin_rdy;
    sc_out < bool > dout_vld;
    sc_in < bool > dout_rdy;


    //les processus principales
    void ham_main_din();   //processus de codage
    void ham_main_codedin();  //processus de decodage

	//constructeur
	SC_CTOR(HamReg){
		//pour la generation d'un mot de code
		hgen=new HCGen("hgen");
		hgen->din( din );
		hgen->dout( coded_dout );
		hgen->clk(clk);
		hgen->din_rdy(din_rdy);
		hgen->din_vld(din_vld);
		hgen->codedout_rdy(codedout_rdy);
		hgen->codedout_vld(codedout_vld);



         //pour le calcule du syndrome
		sgen=new SynGen("sgen");
		sgen->din( coded_din );
        sgen->dout( syndSig );
        sgen->clk(clk);

        //pour la correction d'un mot de code et la decoder
		corr=new Corrector("corr");
		corr->datain( coded_din );
		corr->syndin( syndSig );
		corr->dout( dout );
		corr->clk(clk);
		corr->codedin_rdy(codedin_rdy);
		corr->codedin_vld(codedin_vld);
		corr->dout_rdy(dout_rdy);
		corr->dout_vld(dout_vld);


		SC_CTHREAD(ham_main_din,clk.pos());
		SC_CTHREAD(ham_main_codedin,clk.pos());

		sensitive << din;
		sensitive << din_vld;
		sensitive << clk.pos();
	}
	~HamReg(){   //le destructeur
     delete hgen;
     delete sgen;
     delete corr;
	}
};

#endif
