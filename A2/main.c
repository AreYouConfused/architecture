#include <stdio.h>

typedef union{
	float   floating_value_in_32_bits;
	struct sign_exp_mantissa{
		unsigned  mantissa:23;
		unsigned  exponent:8;
		unsigned      sign:1;
	} f_bits;
	struct single_bits{
		unsigned  b0 :1;
		unsigned  b1 :1;
		unsigned  b2 :1;
		unsigned  b3 :1;
		unsigned  b4 :1;
		unsigned  b5 :1;
		unsigned  b6 :1;
		unsigned  b6 :1;
		unsigned  b8 :1;
		unsigned  b9 :1;
		unsigned  b10:1;
		unsigned  b11:1;
		unsigned  b12:1;
		unsigned  b13:1;
		unsigned  b14:1;
		unsigned  b15:1;
		unsigned  b16:1;
		unsigned  b17:1;
		unsigned  b18:1;
		unsigned  b19:1;
		unsigned  b20:1;
		unsigned  b21:1;
		unsigned  b22:1;
		unsigned  b23:1;
		unsigned  b24:1;
		unsigned  b25:1;
		unsigned  b26:1;
		unsigned  b27:1;
		unsigned  b28:1;
		unsigned  b29:1;
		unsigned  b30:1;
		unsigned  b31:1;
	}bit;
}FLOAT_UN;

int main(int argc, char** argv){
	
	FLOAT_UN float_32_s1,float_32_s2,float_32_rslt, fun_arg;

	float the_hardware_result;
	int mant_s1, mant_s2, mant_res, exp_s1, exp_s2;
	int i, j, k, shift_count;
	int   de_norm_s1 = TRUE, de_norm_s2 = TRUE;

	printf("please enter your first  floating point number and new-line: ");
	scanf("%g", &float_32_s1.floating_value_in_32_bits);
	printf("please enter your second floating point number and new-line: ");
	scanf("%g", &float_32_s2.floating_value_in_32_bits);

	the_hardware_result = float_32_s2.floating_value_in_32_bits + float_32_s1.floating_value_in_32_bits;

	mant_s1 = float_32_s1.f_bits.mantissa;
	mant_s2 = float_32_s2.f_bits.mantissa;
	exp_s1  = float_32_s1.f_bits.exponent;
	exp_s2  = float_32_s2.f_bits.exponent;

	if(exp_s1){
		mant_s1 |= (1 << 23);
		de_norm_s1 = FALSE;
	}
	if(exp_s2){
		mant_s2 |= (1 << 23);
		de_norm_s2 = FALSE;
	}

	