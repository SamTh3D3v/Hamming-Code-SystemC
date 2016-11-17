#include "Corrector.h"

void Corrector::correct()
{
	sc_uint <15> syndMatrice[4];
	syndMatrice[0]=32520; //111111100001000
	syndMatrice[1]=30948; //111100011100100
	syndMatrice[2]=26322; //110011011010010
	syndMatrice[3]=21937; //101010110110001

	dout_vld.write(0);
	while(true){
		sc_uint<15> tmpData;
		sc_uint<4> tmpSyn;
		sc_uint<11> res;

		int pow=1,cpt=0;
		codedin_rdy.write(1);
		do{
			wait();
		}while(! codedin_vld.read());

		tmpSyn=syndin.read();  cout <<"\n SYN == "<<tmpSyn<<" \n"<<endl;
		tmpData=datain.read();

		codedin_rdy.write(0);
		//the correction
		if(tmpSyn != 0 )
		{
			//there is a mistake in the data
			/*for(int i=0;i<4;i++){
				tmpSyn.bit(i) == syndMatrice[i];
			}*/
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
			if(j<15)
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
	dout_vld.write(1);
	dout.write(res);
	do{
		wait();
	}while(! dout_rdy.read());
	dout_vld.write(0);
}

}
