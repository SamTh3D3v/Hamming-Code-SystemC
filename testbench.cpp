#include "testbench.h"

/*
void tbreg::clkInput(){
	while(true){
		for(int i=1;i<=20;i++){
			clk=(sc_logic)'0';
			wait(5,SC_NS);
			clk=(sc_logic)'1';
			wait(5,SC_NS);
		}
		wait();
	}
}
*/
//Process Statement
void tbreg::send(){
	//l'envoie des données a codé
	din_vld.write(0);


	for(int i=0;i<128; i++){


		din_vld.write(1);
		din.write(i);
		cout << i << " din<11> : \t" << i <<endl;

		do{
			wait();
		}while(!dout_rdy.read());
		din_vld.write(0);

 	}
}
void tbreg::receive(){
	sc_uint <15> coded_data_tmp;

	codedout_rdy.write(0);
	for(int i=0;i<128; i++){

		codedout_rdy.write(1);
		do{
					wait();
		 }while(!codedout_vld.read());
		coded_data_tmp=coded_dout.read();
		wait();
		cout << i << "coded_dout<15> : \t" << coded_data_tmp <<endl;
		codedout_rdy.write(0);
	}

	//terminer la simulation
	sc_stop();
}
