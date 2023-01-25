#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "solver.h"
#include "matrix.h"

int check_matrix( matrix_t *eqs){
	for( int i = 0; i < eqs->rn; i++){
		if( eqs->e[i + i * eqs->cn] == 0 )
			return 1;
	}

	return 2;
}

void change_matrix( matrix_t *eqs ){
	for( int i = 0; i < eqs->rn; i++ ){
		static int a = 0;              // zmienna do zamiany wierszy
		double max = fabs(eqs->e[i]);

		for( int j = 0; j < eqs->rn; j++ ){
			if( fabs(eqs->e[j * eqs->cn + i]) > max )
					max = fabs( eqs->e[j * eqs->cn +i]);
		}

		if( fabs(eqs->e[i + i*eqs->cn]) == max ){
			xchg_rows( eqs, a, i );     // zmaien a-ty wiersz z i-tym
			a++;
		}
	}

	for( int i = 0; i < (eqs->rn * eqs->cn); i++ )
		printf("%g ", eqs->e[i]);
}

void solver( matrix_t *eqs ){
	double *x = malloc( sizeof(double) * eqs->rn ); // wektor wynikowy
	for( int i = 0; i < eqs->rn; i++ )                // przypisanie wektorowi wartości początkowych
		x[i] = 0;
	
	for( int z = 0; z < 1000000; z++ ){
		for( int j = 0; j < eqs->rn; j++ ){
			double d = eqs->e[(eqs->cn)*(j+1) - 1];       // wyraz wolny
		
			for( int i = 0; i < eqs->rn; i++ ){
				if( i != j )                             // pomijanie elementu na digonali
					d -= eqs->e[eqs->cn * j + i] * x[i];   // kolejne wyrazy pomnożone przez wektor wynikowy
			}
			
			x[j] = d / eqs->e[eqs->cn * j + j]; 
		}
	}

	for(int i = 0; i < eqs->rn; i++ )
		eqs->e[(i+1) * eqs->cn - 1] = x[i];
	free(x);
}
