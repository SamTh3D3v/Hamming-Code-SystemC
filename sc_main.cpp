#include <systemc.h>
#include "HammingRegister.h"
#include "testbench.h"



int sc_main(int argc, char* argv){
	sc_signal< sc_logic > clk;
	sc_signal< sc_uint<11> > din;
	sc_signal< sc_uint<11> > out;

shift shift("reg_decalage");
shift.clk(clk);
shift.din(din);
shift.dout(out);

testbenchreg test("test");
test.clk(clk);
test.din(din);
test.dout(out);

sc_start();
return 0;
}
