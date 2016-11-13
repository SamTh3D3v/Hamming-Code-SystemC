#include "systemc.h"

SC_MODULE(shiftD)
{
  //Ports
  sc_in <sc_logic> clk;
  sc_in < sc_uint<11> > din;
  sc_out < sc_uint<11> > dout;


  //processus principal
  void shifterD();

  //constructeur
  SC_CTOR(shiftD)
    {SC_METHOD(shifterD);
    sensitive << clk.pos();
    }

};

