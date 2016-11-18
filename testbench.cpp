#include "testbench.h"
#include <bitset>
#include <iostream>

using namespace std;


void tbreg::send(){
	//l'envoie des données a coder
	din_vld.write(0);
	for(int i=0;i<128; i++){
		din_vld.write(1);

		din.write(i);

		do{
			wait();    //tant que din n'est pret on attend
		}while(!din_rdy.read());
		din_vld.write(0);
 	}

	//l'envoie des données a décoder

	codedin_vld.write(0);
	for(int i=0;i<128; i++){
		codedin_vld.write(1);

		coded_din.write(i);

		do{
			wait();   //tant que coded_din n'est pret on attend
		}while(!codedin_rdy.read());
		codedin_vld.write(0);
	}
}
void tbreg::receive(){
	sc_uint <15> coded_data_tmp;
	codedout_rdy.write(0);

	cout << "\n ****** LE CODAGE ****** \n"<<endl;
	for(int i=0;i<128; i++){

		codedout_rdy.write(1);
		do{
			wait();            //tant que coded_dout ne contient pas de données valide on attend
		 }while(!codedout_vld.read());
		coded_data_tmp=coded_dout.read();
		cout <<" un mot de <11> bits : "<< std::bitset<11>(i) << " -> code de Hamming sur <15> bits : \t" << std::bitset<15>(coded_data_tmp) <<endl;
		codedout_rdy.write(0);
	}

	//recuperation des données decodées et corrigées
	cout << "\n ****** LE DECODAGE ****** \n"<<endl;
	sc_uint <11> corrected_data_tmp;
	dout_rdy.write(0);
	for(int i=0;i<128; i++){

		dout_rdy.write(1);
		do{
			wait();  //tant que il n'y a pas de données valides à recuperer on attend
		}while(!dout_vld.read());
		corrected_data_tmp=dout.read();
			//wait();
		cout <<" un mot de code de <15> bits: "<< std::bitset<15>(i) << " -> apres la correction et le docodage <11> bits : " << std::bitset<11>(corrected_data_tmp) <<endl;
		dout_rdy.write(0);
	}

	//terminer la simulation une fois qu'on a testé ces valeurs
	sc_stop();
}
