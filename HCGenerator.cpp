#include "HCGenerator.h"

void HCGen::generate()
{
	sc_uint <15> res;
	sc_uint <11> tmp;

	sc_logic p1, p2, p3, p4;

	tmp=din.read();
	p1=tmp.bit(0)^ tmp.bit(1)^tmp.bit(3)^tmp.bit(4)^tmp.bit(6)^tmp.bit(8)^tmp.bit(10);
	p2=tmp.bit(0)^ tmp.bit(2)^tmp.bit(3)^tmp.bit(5)^tmp.bit(6)^tmp.bit(9)^tmp.bit(10);
	p3=tmp.bit(1)^ tmp.bit(2)^tmp.bit(3)^tmp.bit(7)^tmp.bit(8)^tmp.bit(9)^tmp.bit(10);
	p4=tmp.bit(4)^ tmp.bit(5)^tmp.bit(6)^tmp.bit(7)^tmp.bit(8)^tmp.bit(9)^tmp.bit(10);

//to be updated with a much sofisticated solution
   res.set(0,(bool)p1); //*
   res.set(1,(bool)p2); //*
   res.set(2,(bool)tmp.bit(0));
   res.set(3,(bool)p3); //*
   res.set(4,(bool)tmp.bit(1));
   res.set(5,(bool)tmp.bit(2));
   res.set(6,(bool)tmp.bit(3));
   res.set(7,(bool)p4); //*

   res.set(8,(bool)tmp.bit(4));
   res.set(9,(bool)tmp.bit(5));
   res.set(10,(bool)tmp.bit(6));
   res.set(11,(bool)tmp.bit(7));
   res.set(12,(bool)tmp.bit(8));
   res.set(13,(bool)tmp.bit(9));
   res.set(14,(bool)tmp.bit(10));

	dout.write(res);
}
