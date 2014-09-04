/*
 * debug.c
 *
 *  Created on: 25.08.2014
 *      Author: s.von.hall
 */

# define groesse 5000
#include <stdio.h>
#include <stdlib.h>

void w(int * x, int * y){
	int * j;
	j=x;
	x=y;
	y=j;
}

void s(int * in,int * si){
	int i;
	int * st,*e,*m;
	if ((si-in)>1){
	st=in;
	e=si;
	m=st+((*si-*in)/2);
	do{
		while(st<m){
			st++;
		}
		while(e>m){
			e--;
		}
		if(st<=e){
		w(st,e);
		st++;
		e--;}
	}while(st<=e);
	s(in,e);
	s(st,si);
	}
}


void m(int * ein){
	int * h;
	int i;
	int l,k,*n;
	h=malloc(20*sizeof(int));
	for (i=0;i<groesse;i=i+20){
	memcpy(h,ein+i,20*sizeof(int));
	s(h,h+20);
	memcpy(ein+i,h,20*sizeof(int));
	}
	free(h);
	for(i=20;i<=groesse;i++){
	h=ein+i;
	k=i;
	l=*h;
	for(n=ein;*(n)<*h;n++){
		k--;
	}
	memcpy(n+1,n,k*sizeof(int));
	*(n)=l;
	}

}


void main(){
	unsigned int z[groesse];
	int i;
	for(i=0;i<groesse;i++){
		*(z+i)=groesse-i;
	}
	m(z+1);

	for(i=0;i<groesse;i++){
		printf("%d ",z[i]);
	}
}



