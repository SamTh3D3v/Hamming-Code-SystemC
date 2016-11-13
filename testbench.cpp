#include "testbench.h"


void testbenchreg::clkInput(){
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
//Process Statement
void testbenchreg::dinInput(){
	while(true){
		for(int i=1; i<=4;i++){
			din.write(0);
			wait(13,SC_NS);
			din.write(1);
			wait(12,SC_NS);
		}
		wait();
	}
}
void testbenchreg::display(){
	cout << sc_time_stamp()<<"::";
	cout <<"(din, clk): ";
	cout << din << clk;
	cout << " (dout):" << dout <<endl;
}
