#include "SynGenerator.h"

void SynGen::calculate()
{
	sc_uint <4> syndrome;
	sc_uint <15> data;
	sc_uint <15> syndMatrice[4];
	bool tmp=0;

	data=din.read();
	//la  matrice H qui permet de calculer le syndrome
	syndMatrice[0]=32520; //111111100001000
	syndMatrice[1]=30948; //111100011100100
	syndMatrice[2]=26322; //110011011010010
	syndMatrice[3]=21937; //101010110110001

	for(int j=0;j<4;j++){
		for(int i=0;i<15;i++){
			tmp =tmp | (syndMatrice[j].bit(i) & data.bit(i));
		}
		syndrome.set(j,(bool)tmp);
	}
	dout.write(syndrome);
}
