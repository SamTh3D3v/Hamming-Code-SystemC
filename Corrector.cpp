#include "Corrector.h"

void Corrector::correct()
{
	//la matrice de parité (15, 11)
	sc_uint <15> syndMatrice[4];
	syndMatrice[0]=2040;  //000011111111000
	syndMatrice[1]=14580; //011100011110100
	syndMatrice[2]=23346; //101101100110010
	syndMatrice[3]=27985; //110110101010001

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

		tmpSyn=syndin.read();
		tmpData=datain.read();

		codedin_rdy.write(0);
		//La correction
		if(tmpSyn != 0 )  //si le syndrome =0 donc il n'y a pas d'erreur
		{
			int j=0;
			bool cont=true;
			while(cont && j<15){
				if(tmpSyn.bit(3) == syndMatrice[0].bit(j) &&
						tmpSyn.bit(2) == syndMatrice[1].bit(j) &&
						tmpSyn.bit(1) == syndMatrice[2].bit(j) &&
						tmpSyn.bit(0) == syndMatrice[3].bit(j)){
					cont =false;
				}else{
					j++;
				}
			}
			if(cont==true){
				//Erreur: exit();
			}
			// La correction de l'erreur
			if(j<15)
			tmpData.set(j,!tmpData.bit(j));
		}
		//le decodage de donnée (extraire du 11 bits a partir du mot de code  )
		for(int i=0;i<11;i++)
		{
			res.set(i, tmpData.bit(i +4));
		}
	dout_vld.write(1);
	dout.write(res);
	do{
		wait();
	}while(! dout_rdy.read());
	dout_vld.write(0);
	}

}
