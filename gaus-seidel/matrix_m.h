// zawiera jedynie "definicję" struktury matrix_t

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct{
	int rn;
	int cn;
	double *e;
} matrix_t;

#endif
