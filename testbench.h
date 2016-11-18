#ifndef TESTBENCH_               //pour eviter le probleme d'inclusion infinie
#define TESTBENCH_

#include <systemc.h>


SC_MODULE (tbreg){
//l'horloge
	sc_in <bool> clk;

	sc_out < sc_uint<11> > din;  //pour envoyer le mot à coder
	sc_in < sc_uint<15> > coded_dout;  //pour recupérer le mot codé


	sc_out < sc_uint<15> > coded_din; //pour envoyer un mot de code
    sc_in < sc_uint<11> > dout; //pour recuperer le mot corrigé et decodé


    //les signaux de handshake
    //* pour din
    sc_out < bool > din_vld;  //valide
    sc_in < bool > din_rdy;   //pret
    //* pour coded_dout
    sc_in < bool > codedout_vld;
    sc_out < bool > codedout_rdy;
    //* pour coded_din
    sc_out < bool > codedin_vld;
    sc_in < bool > codedin_rdy;
    //*pour dout
    sc_in < bool > dout_vld;
    sc_out < bool > dout_rdy;

	void send();   //pour envoyer des mots a coder
	void receive();  //pour recuperer les mots codes

	SC_CTOR(tbreg){
		SC_CTHREAD(send,clk);
		SC_CTHREAD(receive,clk);
		 sensitive << clk.pos();
	}
};


#endif
