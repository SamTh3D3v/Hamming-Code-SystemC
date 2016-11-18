#include "SynGenerator.h"
#include <bitset>
#include <iostream>

void SynGen::calculate()
{
	sc_uint <4> syndrome;
	sc_uint <15> data;
	sc_uint <15> syndMatrice[4];
	int tmp=0;

	data=din.read();
	//la  matrice H qui permet de calculer le syndrome
	syndMatrice[0]=2040;  //000011111111000      //la matrice de parité H, H*data=syndrome
	syndMatrice[1]=14580; //011100011110100
	syndMatrice[2]=23346; //101101100110010
	syndMatrice[3]=27985; //110110101010001

	for(int j=0;j<4;j++){
		tmp=0;
		for(int i=0;i<15;i++){
			tmp =tmp + (syndMatrice[j].bit(14-i) * data.bit(14-i));
		}
		syndrome.set(3-j,tmp % 2);
	}
	dout.write(syndrome);

	//* decommenter pour afficher les valeurs des syndromes
	//cout << "le syndrome pour le mot :"<<std::bitset<15>(data) <<", est >>"<<std::bitset<4>(syndrome) << endl;
}
