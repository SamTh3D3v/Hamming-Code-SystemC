#include "testbench.h"
#include <bitset>
#include <iostream>

using namespace std;
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
		do{
			wait();
		}while(!din_rdy.read());
		din_vld.write(0);
 	}

	//lenvoi des données a décodés
	//-- recuperer les données a partir d'un fichier

	    codedin_vld.write(0);
		for(int i=0;i<128; i++){
			codedin_vld.write(1);
			coded_din.write(1353);
			do{
				wait();
			}while(!codedin_rdy.read());
			codedin_vld.write(0);
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
		//wait();
		cout <<" din<11>: \t"<< std::bitset<11>(i) << " -> coded_dout<15> : \t" << std::bitset<15>(coded_data_tmp) <<endl;
		codedout_rdy.write(0);
	}

	//recuperation des données decodées
cout << "\n le decodage \n"<<endl;
	sc_uint <11> corrected_data_tmp;
	dout_rdy.write(0);
	for(int i=0;i<128; i++){

		dout_rdy.write(1);
		do{
			wait();
		}while(!dout_vld.read());
		corrected_data_tmp=dout.read();
			//wait();
		cout <<" codeddata<15>: \t"<< std::bitset<15>(i) << " -> decoded/corrected data<11> : \t" << std::bitset<11>(corrected_data_tmp) <<endl;
		dout_rdy.write(0);
	}



	//terminer la simulation
	sc_stop();
}
