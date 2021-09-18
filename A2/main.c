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
		unsigned  b7 :1;
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

void printBitString(FLOAT_UN);

int main(int argc, char** argv){
	
	FLOAT_UN float_32_s1,float_32_s2,float_32_rslt;

	float the_hardware_result;
	int mant_s1, mant_s2, mant_res, exp_s1, exp_s2;
	int shift_count;
	int   de_norm_s1 = 1, de_norm_s2 = 1;

	printf("Please enter two positive floating point values each with:\n\
			\r\t- no more than 6 significant digits\n\
    		\r\t- a value between   +   10**37 and 10**-37\n\n");

	printf("Enter Float 1: ");
	scanf("%g", &float_32_s1.floating_value_in_32_bits);
	printf("Enter Float 2: ");
	scanf("%g", &float_32_s2.floating_value_in_32_bits);

	the_hardware_result = float_32_s2.floating_value_in_32_bits + float_32_s1.floating_value_in_32_bits;

	mant_s1 = float_32_s1.f_bits.mantissa;
	mant_s2 = float_32_s2.f_bits.mantissa;
	exp_s1  = float_32_s1.f_bits.exponent;
	exp_s2  = float_32_s2.f_bits.exponent;

	if(exp_s1){
		mant_s1 |= (1 << 23);
		de_norm_s1 = 0;
	}
	if(exp_s2){
		mant_s2 |= (1 << 23);
		de_norm_s2 = 0;
	}

	if((shift_count = exp_s1 - exp_s2) < 0){
		shift_count = -(shift_count);    /* keep diff + */
		if(shift_count > 24)shift_count = 24;
		if(shift_count >= 1 && de_norm_s1){
			mant_s1 = (mant_s1 >> (shift_count - 1));
		}else{
			mant_s1 = mant_s1 >> shift_count;}
			float_32_rslt.f_bits.exponent = exp_s2;
	}else{
		if(shift_count > 24)shift_count = 24;
		if(shift_count >= 1 && de_norm_s2){
			mant_s2 = (mant_s2 >> (shift_count - 1));
		}else{
			mant_s2 = mant_s2 >> shift_count;}
			float_32_rslt.f_bits.exponent = exp_s1;
	}

	mant_res = mant_s1 + mant_s2;

	if(mant_res & (1<<24)){
		mant_res >>= 1;
		float_32_rslt.f_bits.exponent++;
		printf("\n2 HIDDEN BITS, MUST INCREMENT EXPONENT\n");
		float_32_rslt.f_bits.mantissa = (mant_res & ~(1<<23));
	}else{
		float_32_rslt.f_bits.mantissa = (mant_res & ~(1<<23));
	}
	printf("\nOriginal patter of Float 1: ");
	printBitString(float_32_s1);
	printf("Original patter of Float 2: ");
	printBitString(float_32_s2);	
	printf("Bit patter of result      : ");
	printBitString(float_32_rslt);

	printf("\nHARDWARE FLOATING RESULT FROM PRINTF ==>>> %f\n", the_hardware_result);

	if (float_32_rslt.f_bits.exponent == 0 || float_32_rslt.f_bits.exponent == 255){
		printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> inf\n");
	} else {
		printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %f\n", float_32_rslt.floating_value_in_32_bits);
	}

	return 0;
}

void printBitString(FLOAT_UN float_32){
	char bit_string[43];

	int i;

	for(i=0; i<42; i++){
		bit_string[i] = ' ';
	}
	bit_string[42] = '\0';

	bit_string[0] = float_32.bit.b31?'1':'0';

	bit_string[2] = float_32.bit.b30?'1':'0';
	bit_string[3] = float_32.bit.b29?'1':'0';
	bit_string[4] = float_32.bit.b28?'1':'0';
	bit_string[5] = float_32.bit.b27?'1':'0';

	bit_string[7] = float_32.bit.b26?'1':'0';
	bit_string[8] = float_32.bit.b25?'1':'0';
	bit_string[9] = float_32.bit.b24?'1':'0';
	bit_string[10] = float_32.bit.b23?'1':'0';

	bit_string[12] = float_32.bit.b22?'1':'0';
	bit_string[13] = float_32.bit.b21?'1':'0';
	bit_string[14] = float_32.bit.b20?'1':'0';

	bit_string[16] = float_32.bit.b19?'1':'0';
	bit_string[17] = float_32.bit.b18?'1':'0';
	bit_string[18] = float_32.bit.b17?'1':'0';
	bit_string[19] = float_32.bit.b16?'1':'0';

	bit_string[21] = float_32.bit.b15?'1':'0';
	bit_string[22] = float_32.bit.b14?'1':'0';
	bit_string[23] = float_32.bit.b13?'1':'0';
	bit_string[24] = float_32.bit.b12?'1':'0';

	bit_string[26] = float_32.bit.b11?'1':'0';
	bit_string[27] = float_32.bit.b10?'1':'0';
	bit_string[28] = float_32.bit.b9?'1':'0';
	bit_string[29] = float_32.bit.b8?'1':'0';

	bit_string[31] = float_32.bit.b7?'1':'0';
	bit_string[32] = float_32.bit.b6?'1':'0';
	bit_string[33] = float_32.bit.b5?'1':'0';
	bit_string[34] = float_32.bit.b4?'1':'0';

	bit_string[36] = float_32.bit.b3?'1':'0';
	bit_string[37] = float_32.bit.b2?'1':'0';
	bit_string[38] = float_32.bit.b1?'1':'0';
	bit_string[39] = float_32.bit.b0?'1':'0';
	printf("%s\n", bit_string);
}