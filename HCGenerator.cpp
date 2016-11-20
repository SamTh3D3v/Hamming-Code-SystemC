#include "HCGenerator.h"

void HCGen::generate()
{

while(true){

	sc_uint <15> res;
	sc_uint <11> tmp;

	bool p1, p2, p3, p4;  //parity bits

	din_rdy.write(1);
	    	do{
	    		wait();
	}while(! din_vld.read());

	tmp=din.read();
	din_rdy.write(0);

	p1= tmp.bit(10-0)^tmp.bit(10-1)^tmp.bit(10-3)^tmp.bit(10-4)^tmp.bit(10-6)^tmp.bit(10-8)^tmp.bit(10-10);
	p2= tmp.bit(10-0)^tmp.bit(10-2)^tmp.bit(10-3)^tmp.bit(10-5)^tmp.bit(10-6)^tmp.bit(10-9)^tmp.bit(10-10);
	p3=tmp.bit(10-1)^ tmp.bit(10-2)^tmp.bit(10-3)^tmp.bit(10-7)^tmp.bit(10-8)^tmp.bit(10-9)^tmp.bit(10-10);
	p4=tmp.bit(10-4)^ tmp.bit(10-5)^tmp.bit(10-6)^tmp.bit(10-7)^tmp.bit(10-8)^tmp.bit(10-9)^tmp.bit(10-10);

	//too lazy to add a looop :p
   res.set(14,(bool)tmp.bit(10));
   res.set(13,(bool)tmp.bit(9));
   res.set(12,(bool)tmp.bit(8));
   res.set(11,(bool)tmp.bit(7));
   res.set(10,(bool)tmp.bit(6));
   res.set(9,(bool)tmp.bit(5));
   res.set(8,(bool)tmp.bit(4));
   res.set(7,(bool)tmp.bit(3));
   res.set(6,(bool)tmp.bit(2));
   res.set(5,(bool)tmp.bit(1));
   res.set(4,(bool)tmp.bit(0));
   //yes i am not too lazy to add comments tho -|-
   //parity bits
   res.set(3,(bool)p1); //*
   res.set(2,(bool)p2); //*
   res.set(1,(bool)p3); //*
   res.set(0,(bool)p4); //*

    codedout_vld.write(1);
	dout.write(res);

	do{
		wait();
	}while(! codedout_rdy.read());
	codedout_vld.write(0);
}
}
