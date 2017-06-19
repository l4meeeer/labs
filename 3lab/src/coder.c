#include "coder.h"

int encode(uint32_t code_point, CodeUnits *code_units){
if(code_units == NULL){
	return -1;
}
if(code_point < 128){
    code_units->length = 1;
    	uint8_t num = 127 & code_point;
   		code_units->code[0] = num;
   		return 0;
   		
}

if((code_point < 2048)&&(code_point > 127)){
	code_units->length = 2;
		uint32_t num = code_point >> 6;
		uint8_t num1 = 192 | num;
		code_units->code[0] = num1;
		num = code_point & 63;
		num1 = 128 | num;
		code_units->code[1] = num1;
		return 0;
}

if((code_point < 65536)&&(code_point > 2047)){
	code_units->length = 3;
		uint32_t num = code_point >> 12;
		uint8_t num1 = 224 | num;
		code_units->code[0] = num1;
		num = code_point >> 6;
		num = num & 63;
		num1 = 128 | num;
		code_units->code[1] = num1;
		num = code_point & 63;
		num1 = 128 | num;
		code_units->code[2] = num1;
		return 0;
}

if((code_point < 2097152)&&(code_point > 65535)){
	code_units->length = 4;
		uint32_t num = code_point >> 18;
		uint8_t num1 = 240 | num;
		code_units->code[0] = num1;
		num = code_point >> 12;
		num = num & 63;
		num1 = 128 | num;
		code_units->code[1] = num1;
		num = code_point >> 6;
		num = num & 63;
		num1 = 128 | num;
		code_units->code[2] = num1;
		num = code_point & 63;
		num1 = 128 | num;
		code_units->code[3] = num1;
		return 0;
	
}
printf("Wrong number\n");
return -1;
}

uint32_t decode(const CodeUnits *code_unit){
	if((code_unit->code[0] & 128) == 0){
		uint32_t dec = code_unit->code[0];
			return dec;
	}
	
	if((code_unit->code[0] & 224) == 192){
		uint32_t dec = code_unit->code[0] & 31;
		dec = dec << 6;
		uint8_t dec1 =  code_unit->code[1] & 63;
		return dec = dec | dec1;
	}
	
	if((code_unit->code[0] & 240) == 224){
		uint32_t dec = code_unit->code[0] & 15;
		dec = dec << 6;
		uint8_t dec1 = code_unit->code[1] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[2] & 63;
		return dec = dec | dec1;
	}

	if((code_unit->code[0] & 248) == 240){
		uint32_t dec = code_unit->code[0] & 7;
		dec = dec << 6;
		uint8_t dec1 = code_unit->code[1] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[2] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[3] & 63;
		return dec = dec| dec1;	
	}
	
	return -1;
}
