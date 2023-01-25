#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "seidel.h"

int main(){
	matrix_t *eqs = malloc( sizeof *eqs);
	
	double e[] = {2, 3, 11, 5, 7, 13};

	eqs->e = malloc( sizeof(double) * 6);
	
	eqs->e[0] = 2;
	eqs->e[1] = 3;
	eqs->e[2] = 11;
	eqs->e[3] = 5;
	eqs->e[4] = 7;
	eqs->e[5] = 13;

	eqs->rn = 2;
	eqs->cn = 3;

	printf("%g\n", eqs->e[0]);
	printf("%g\n", eqs->e[1]);
	printf("%g\n\n\n", eqs->e[2]);

	if( seidel( eqs ) == 1)
		return 1;

	printf("%g\n", eqs->e[3]);

	printf("po rozwiazaniu: \n");

	for( int i = 0; i < 6; i++ )
		printf( "%g ", eqs->e[i] );

	return 0;
}
