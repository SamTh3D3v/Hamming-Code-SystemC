#ifndef HAMMINGREG_
#define HAMMINGREG_

#include <systemc.h>
#include "HCGenerator.h"
#include "SynGenerator.h"
#include "Corrector.h"


//code and decode words using hamming code

SC_MODULE(HamReg)
{
	HCGen *hgen;  //this circuit generate a code word
	SynGen *sgen;  //this circuit calculate the syndrome
	Corrector *corr; //this circuit correct and decode a word

	//Ports
	sc_in < bool > clk;
	sc_in < sc_uint<15> > coded_din;
	sc_out < sc_uint<15> > coded_dout;


	sc_in < sc_uint<11> > din;
    sc_out < sc_uint<11> > dout;

    //signals to connect between the modules
    sc_signal < sc_uint <4> > syndSig;
    sc_signal< sc_uint <11> > din_sig;
    sc_signal< sc_uint <15> > codeddout_sig;

    // handshake signals
    sc_in < bool > din_vld;
    sc_out < bool > din_rdy;
    sc_out < bool > codedout_vld;
    sc_in < bool > codedout_rdy;


    sc_in < bool > codedin_vld;
    sc_out < bool > codedin_rdy;
    sc_out < bool > dout_vld;
    sc_in < bool > dout_rdy;



    void ham_main_din();   //coding process
    void ham_main_codedin();  //decoding process

	SC_CTOR(HamReg){

		hgen=new HCGen("hgen");
		hgen->din( din );
		hgen->dout( coded_dout );
		hgen->clk(clk);
		hgen->din_rdy(din_rdy);
		hgen->din_vld(din_vld);
		hgen->codedout_rdy(codedout_rdy);
		hgen->codedout_vld(codedout_vld);

		sgen=new SynGen("sgen");
		sgen->din( coded_din );
        sgen->dout( syndSig );
        sgen->clk(clk);

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
	~HamReg(){
     delete hgen;
     delete sgen;
     delete corr;
	}
};

#endif
