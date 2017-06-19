#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "coder.h"

int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "encode") == 0) {
		encode_file(argv[2], argv[3]);
	} else if (strcmp(argv[1], "decode") == 0) {
		decode_file(argv[2], argv[3]);
	}
	
	return 0;
}
