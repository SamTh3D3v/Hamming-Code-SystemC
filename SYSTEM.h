#ifndef SYSTEM_
#define SYSTEM_

#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"


/*
 * this circuit is to create an instance of the testbench and the hamming code register
 * and connect them */



SC_MODULE(SYSTEMH)
{
	HamReg *hreg;   //the hamming register
	tbreg *tb;   //the test bench module

	//signals to connect the two modules
	sc_signal< sc_uint <11> > din_sig;
	sc_signal< bool > din_sig_vld;
	sc_signal< bool > din_sig_rdy;

	sc_signal< sc_uint <15> > codedout_sig;
	sc_signal< bool > codedout_sig_vld;
	sc_signal< bool > codedout_sig_rdy;

	sc_signal< sc_uint <15> > codedin_sig;
	sc_signal< bool > codedin_sig_vld;
	sc_signal< bool > codedin_sig_rdy;

	sc_signal< sc_uint <11> > dout_sig;
	sc_signal< bool > dout_sig_vld;
	sc_signal< bool > dout_sig_rdy;

	sc_clock clk_sig;

	SC_CTOR(SYSTEMH)
	:clk_sig("clk_sig",10, SC_NS)
	{

      hreg=new HamReg("hreg");
      hreg->clk(clk_sig);

      hreg->din(din_sig);
      hreg->din_vld(din_sig_vld);
      hreg->din_rdy(din_sig_rdy);

      hreg->coded_din(codedin_sig);
      hreg->codedin_vld(codedin_sig_vld);
      hreg->codedin_rdy(codedin_sig_rdy);

      hreg->dout(dout_sig);
      hreg->dout_rdy(dout_sig_rdy);
      hreg->dout_vld(dout_sig_vld);

      hreg->coded_dout(codedout_sig);
      hreg->codedout_rdy(codedout_sig_rdy);
      hreg->codedout_vld(codedout_sig_vld);


      tb=new tbreg("tb");
      tb->clk(clk_sig);

      tb->din(din_sig);
      tb->din_vld(din_sig_vld);
      tb->din_rdy(din_sig_rdy);

      tb->coded_din(codedin_sig);
      tb->codedin_vld(codedin_sig_vld);
      tb->codedin_rdy(codedin_sig_rdy);

      tb->dout(dout_sig);
      tb->dout_rdy(dout_sig_rdy);
      tb->dout_vld(dout_sig_vld);

      tb->coded_dout(codedout_sig);
      tb->codedout_rdy(codedout_sig_rdy);
      tb->codedout_vld(codedout_sig_vld);
	}
	~SYSTEMH(){
     delete tb;
     delete hreg;
	}
};


#endif
