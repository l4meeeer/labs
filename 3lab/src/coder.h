#ifndef _CODER_H
#define _CODER_H

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum {
    MaxCodeLength = 4
};

typedef struct {
    uint8_t code[MaxCodeLength];
    uint32_t length;
} CodeUnits;

int encode(uint32_t code_point, CodeUnits *code_units);
uint32_t decode(const CodeUnits *code_unit);

#endif
