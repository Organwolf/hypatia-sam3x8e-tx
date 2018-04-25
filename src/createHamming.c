#include <stdio.h>


/*
* Hamming encoder.
* Author: Jesper Anderberg
*
*/

int dataTosend[8];

uint8_t createHammingCode(uint8_t data[]){

	uint8_t returnByte = 0;
	int p1=0;
	int p2=0;
	int p3=0;

	dataTosend[2]=data[0];
	dataTosend[4]=data[1];
	dataTosend[5]=data[2];
	dataTosend[6]=data[3];
	dataTosend[7]=0;									// Last bit is useless for us, put it to zero.
	p1=dataTosend[2] + dataTosend[4] + dataTosend[6];
	p2=dataTosend[2] + dataTosend[5] + dataTosend[6];
	p3=dataTosend[4] + dataTosend[5] + dataTosend[6];
	

	if(p1%2==0){
		dataTosend[0]=0;
		}else{
		dataTosend[0]=1;
	}

	if(p2%2==0){
		dataTosend[1]=0;
	}
	else{
		dataTosend[1]=1;
	}

	if(p3%2==0){
		dataTosend[3]=0;
	}
	else{
		dataTosend[3]=1;
	}

	for(int i=0; i<8;i++){
		
		if(dataTosend[i]==1){
			returnByte|=(1u<<i);
		}
	}
	return returnByte;
}
