#include "Corrector.h"

void Corrector::correct()
{
	sc_uint<15> tmpData;
	sc_uint<4> tmpSyn;
	sc_uint<11> res;
	sc_uint <15> syndMatrice[4];

int pow=1,cpt=0;

tmpSyn=syndin.read();
tmpData=datain.read();
//the correction
if(tmpSyn != 0 )
{
	//there is a mistake in the data
	for(int i=0;i<4;i++){
		tmpSyn.bit(i) == syndMatrice[i];
	}
	int j=0;
	bool cont=true;
   while(cont && j<15){
	   if(tmpSyn.bit(0) == syndMatrice[0].bit(j) &&
	      tmpSyn.bit(1) == syndMatrice[1].bit(j) &&
		  tmpSyn.bit(2) == syndMatrice[2].bit(j) &&
		  tmpSyn.bit(3) == syndMatrice[3].bit(j)){
		   cont =false;
	   }else{
		   j++;
	   }
   }
   if(cont==true){
	   //Something went wrong
   }
// correcting the error
   tmpData.set(j,!tmpData.bit(j));
}


//generation of data
for(int i=1;i<=15;i++)
{
	if(i==pow){
       pow *=2;
	}else{
		res.set(cpt, tmpData.bit(i-1));
		cpt++;
	}
}
	dout.write(res);
}
