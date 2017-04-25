# ARPACK++ v1.2 2/18/2000
# c++ interface to ARPACK code.
# This file contains some definitions used to compile arpack++ examples
# with the g++ compiler under linux.


# Defining the machine.

PLAT         = MacOS

# Defining the compiler.

CPP          = clang++

# Defining ARPACK++ directories.
# ARPACKPP_INC is the directory that contains all arpack++ header files.
# SUPERLU_DIR and UMFPACK_DIR must be set to ARPACKPP_INC.

SED = /Users/yuping37/Documents/Projects/SED
ARPACKPP_DIR = $(SED)/arpack++
ARPACKPP_INC = $(ARPACKPP_DIR)/include
SUPERLU_DIR  = $(ARPACKPP_INC)
UMFPACK_DIR  = $(ARPACKPP_INC)

# Defining ARPACK, LAPACK, UMFPACK, SUPERLU, BLAS and FORTRAN libraries.
# See the arpack++ manual or the README file for directions on how to 
# obtain arpack, umfpack and SuperLU packages. 
# UMFPACK_LIB and SUPERLU_LIB must be declared only if umfpack and superlu 
# are going to be used. Some BLAS and LAPACK fortran routines are 
# distributed along with arpack fortran code, but the user should verify 
# if optimized versions of these libraries are available before installing 
# arpack. The fortran libraries described below are those required to link
# fortran and c++ code using gnu g++ and f77 compiler under linux.
# Other libraries should be defined if the user intends to compile
# arpack++ on another environment.

#ARPACK_LIB   = -larpack
LAPACK_LIB   = -llapack
#SUPERLU_LIB  = -lsuperlu
BLAS_LIB     = -lblas

ARPACK_LIB   = $(SED)/ARPACK/libarpack.a
#LAPACK_LIB   = $(SED)/LAPACK/liblapack.a
UMFPACK_LIB  = $(SED)/UMFPACK/libumfpack.a
SUPERLU_LIB  = -lm $(SED)/SuperLU/superlu.a
#BLAS_LIB     = $(SED)/LAPACK/libblas.a
FORTRAN_LIBS = -lgfortran

# SuiteSparse contains the UMFPACK and CHOLMOD code. To link examples against 
# these, set the SUITESPARSE_DIR to point to your installation:
SUITESPARSE_DIR = $(ARPACKPP_DIR)/../SuiteSparse

UMFPACK_LIB  = $(SUITESPARSE_DIR)/UMFPACK/Lib/libumfpack.a  \
 $(SUITESPARSE_DIR)/CHOLMOD/Lib/libcholmod.a \
 $(SUITESPARSE_DIR)/COLAMD/Lib/libcolamd.a \
 $(SUITESPARSE_DIR)/CCOLAMD/Lib/libccolamd.a \
 $(SUITESPARSE_DIR)/metis-4.0/libmetis.a  \
 $(SUITESPARSE_DIR)/CAMD/Lib/libcamd.a \
 $(SUITESPARSE_DIR)/AMD/Lib/libamd.a \
 $(SUITESPARSE_DIR)/SuiteSparse_config/libsuitesparseconfig.a 
 
CHOLMOD_LIB  = $(SUITESPARSE_DIR)/CHOLMOD/Lib/libcholmod.a \
 $(SUITESPARSE_DIR)/COLAMD/Lib/libcolamd.a \
 $(SUITESPARSE_DIR)/CCOLAMD/Lib/libccolamd.a \
 $(SUITESPARSE_DIR)/metis-4.0/libmetis.a  \
 $(SUITESPARSE_DIR)/CAMD/Lib/libcamd.a \
 $(SUITESPARSE_DIR)/AMD/Lib/libamd.a \

# For cholmod need additional headers:
CHOLMOD_INC  = -I$(SUITESPARSE_DIR)/CHOLMOD/Include -I$(SUITESPARSE_DIR)/SuiteSparse_config


# Defining g++ flags and directories.

# CPP_WARNINGS = -fpermissive 
CPP_WARNINGS = -Wall -ansi -pedantic-errors
CPP_DEBUG    = -g
CPP_OPTIM    = -O
CPP_LIBS     = 
CPP_INC      = 

CPP_FLAGS    = -arch x86_64 $(CPP_DEBUG) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC) \
               $(CPP_WARNINGS) -I/usr/local/include -I/usr/X11/include -L/usr/local/Cellar/gcc/6.3.0_1/lib/gcc/6 \
                -L/usr/lib -L/usr/local/lib -L/usr/X11/lib 

# Putting all libraries together.

ALL_LIBS     = $(CPP_LIBS) $(ARPACK_LIB) \
               $(BLAS_LIB) $(LAPACK_LIB) $(FORTRAN_LIBS) 

# defining paths.

vpath %.h  $(ARPACK_INC)

