#include <systemc.h>
#include "HammingRegister.h"



void HamReg::ham_main_din(){

	//initialisation du handshake
   /* din_rdy.write(0);
    codedout_vld.write(0);*/


   // while(true){
    	/*din_rdy.write(1);
    	do{
    		wait();
    	}while(! din_vld.read());*/
    	din.read();
    	//din_rdy.write(0);

    	//wait();


    	/*codedout_vld.write(1);
        //read the coded_dout from outside

    	do{
    		wait();
    	}while(! codedout_rdy.read());
    	codedout_vld.write(0);*/


}

void HamReg::ham_main_codedin(){
	/*codedin_rdy.write(0);
	dout_vld.write(0);*/

  //  while(true){

    	/*codedin_rdy.write(1);
    	do{
    		wait();
    	}while(! codedin_vld.read());*/
    	coded_din.read();
    	/*codedin_rdy.write(0);

    	wait();


    	dout_vld.write(1);
        //read the coded_dout from outside
    	do{
    	    wait();
        }while(! dout_rdy.read());
        dout_vld.write(0);*/


}
