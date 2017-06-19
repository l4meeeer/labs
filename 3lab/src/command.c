#include "command.h"
#include "coder.h"


int encode_file(const char *in_file, const char *out_file)
{

    FILE *in = NULL, *out = NULL;
    in = fopen(in_file, "r");

    if (!in) {
        printf("Error with IN file\n");
        
        return -1;
    }

    out = fopen(out_file, "wb");
    uint32_t point;
    CodeUnits *code_unit = (CodeUnits*)malloc(sizeof(CodeUnits));

    while (!feof(in)) {
        if (!fscanf(in, "%x", &point)) {
           		printf("Error with scan\n");
				fclose(in);
				fclose(out);           		
           		
           		return -1;
        }

			if(feof(in))
				break;
				
            int enc = encode(point, code_unit);
    	    
    	    if (enc != -1) {
    	    	switch (code_unit->length){
    	    	case 1:
    	    		fwrite(code_unit->code, sizeof(uint8_t), 1, out);
        	    break;	
        	    case 2:
        	    	fwrite(code_unit->code, sizeof(uint8_t), 2, out);
        	    break;
        	    case 3:
        	    	fwrite(code_unit->code, sizeof(uint8_t), 3, out);
        	    break;	
    	    	case 4:
        	    	fwrite(code_unit->code, sizeof(uint8_t), 4, out);
        	    break;
        	}
    			
    	}
	}
    fclose(in);
    fclose(out);

    return 0;
}


int decode_file(const char *in_file, const char *out_file)
{
    FILE *in = NULL, *out = NULL;
    in = fopen(in_file, "rb");

    if (!in) {
        printf("Error with open\n");
        
        return -1;
    }
    
    
	out = fopen(out_file, "w");
	uint32_t point;
	CodeUnits *code_unit = (CodeUnits*)malloc(sizeof(CodeUnits));
	
	while(!feof(in)){
		fread(&code_unit->code[0], sizeof(uint8_t), 1, in);
		int j = 0, f = 1;
		if((code_unit->code[0] & 248) == 240){
			j = 3;
		}else{ 
			if((code_unit->code[0] & 240) == 224){
				j = 2;			
			}else{ 
				if((code_unit->code[0] & 224) == 192){
					j = 1;
				}else{ 
					if((code_unit->code[0] & 128) == 0){
						j = 0;
					}else{
						j = -1;
						code_unit->code[0] = 0;								
					}
				}
			}
		}
			
		while((j > 0)&&(!feof(in))){
			fread(&code_unit->code[f], sizeof(uint8_t), 1, in);
			if((code_unit->code[f] & 192) == 128){
				f += 1;
				j -= 1;
			}
		}	
					
				
		if(feof(in))
			break;
			
		if(j == 0){
			int dec = decode(code_unit);
			printf("%x\n", dec);
			if(dec != -1){
				fprintf(out, "%x\n", dec);
			}else{
				printf("Error with encode");
		}	
		}
	}
    fclose(in);
    fclose(out);

    return 0;
}
