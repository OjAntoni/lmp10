// "opakowanie" do wywołania solvera

#include "solver.h"
#include "matrix.h"

int seidel( matrix_t *eqs ){
  	if( check_matrix(eqs) == 1 )
		return 1;

    	//change_matrix( eqs );
	solver(eqs);

	return 0;
}
