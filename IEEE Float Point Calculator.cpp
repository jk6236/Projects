#include <stdio.h>
#include "float.h"

int cast_to_int(float f);

int return_sign(int n);

int return_exp(int n);

float return_mantissa(int n, int exp);

int main(){
	float f;
	scanf("%f", &f);
	int n = 0;
	n = cast_to_int(f);
	int sign = return_sign(n);
	printf("%d\n", sign);
	int exp = return_exp(n);
	printf("%d\n", exp);
	float mantissa = return_mantissa(n , exp);
	printf("%.20f\n", mantissa);
	return 0;
}
//This casts the float to int so that it is easier to work with
int cast_to_int(float f){
	int n = *(int *)&f;
	return n;
}

//This calls exp by creating a mask an comparing the 8 bits of the int casted float and also allows me to consier whether or not it is normalized or denormalized
int return_exp(int n){
	int maskexp = 0b11111111;
	int exp = maskexp & (n >> 23);
	if(exp == 0) exp = -126;
	else exp = exp - 127;
	return exp;
}