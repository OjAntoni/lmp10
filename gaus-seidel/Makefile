libge: seidel.o solver.o matrix.o
	ar rvs libge.a $^

seidel.o solver.o matrix.o: seidel.c seidel.h matrix.h solver.h solver.c matrix.c matrix.h
	cc -c seidel.c solver.c matrix.c

.PHONY: clean

clean:
	-rm *.o libge.a
