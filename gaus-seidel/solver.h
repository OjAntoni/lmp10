#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "matrix.h"

int check_matrix( matrix_t *eqs );

void change_matrix( matrix_t *eqs );

void solver( matrix_t *eqs );

#endif
