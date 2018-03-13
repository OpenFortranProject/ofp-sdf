FORTRAN_ROOT = ../../fortran/syntax

all : CUDA_Fortran.tbl

CUDA_Fortran.tbl : CUDA.def
	sdf2table -i $< -o $@ -m CUDA

CUDA.def : CUDA.sdf
	pack-sdf -i $< -o $@ -Idef $(FORTRAN_ROOT)/Main.def

clean :
	rm -f *.def *.tbl
	rm -f *.aterm
	rm -f *.o *.mod
