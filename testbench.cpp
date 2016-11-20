#include "testbench.h"
#include <bitset>
#include <iostream>

using namespace std;


void tbreg::send(){
	//send the data to encode
	din_vld.write(0);
	for(int i=0;i<128; i++){
		din_vld.write(1);

		din.write(i);

		do{
			wait();
		}while(!din_rdy.read());
		din_vld.write(0);
 	}

	//send the data to decode

	codedin_vld.write(0);
	for(int i=0;i<128; i++){
		codedin_vld.write(1);

		coded_din.write(i);

		do{
			wait();
		}while(!codedin_rdy.read());
		codedin_vld.write(0);
	}
}
void tbreg::receive(){
	sc_uint <15> coded_data_tmp;
	codedout_rdy.write(0);

	cout << "\n ****** THE ENCODING ****** \n"<<endl;
	for(int i=0;i<128; i++){

		codedout_rdy.write(1);
		do{
			wait();
		 }while(!codedout_vld.read());
		coded_data_tmp=coded_dout.read();
		cout <<" a word of <11> bits : "<< std::bitset<11>(i) << " -> its Hamming code on <15> bits : " << std::bitset<15>(coded_data_tmp) <<endl;
		codedout_rdy.write(0);
	}

	cout << "\n ****** THE DECODING ****** \n"<<endl;
	sc_uint <11> corrected_data_tmp;
	dout_rdy.write(0);
	for(int i=0;i<128; i++){

		dout_rdy.write(1);
		do{
			wait();
		}while(!dout_vld.read());
		corrected_data_tmp=dout.read();
			//wait();
		cout <<" a Hamming code word on <15> bits: "<< std::bitset<15>(i) << " -> after the correction and the decoding <11> bits : " << std::bitset<11>(corrected_data_tmp) <<endl;
		dout_rdy.write(0);
	}

	sc_stop(); //stop the simulation
}
