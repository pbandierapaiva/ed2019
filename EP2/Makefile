##################################################################
# Makefile para construção do executável com utilitário make
#
#

C = gcc

consulta: consulta.o cadutil.o
	$(C) -o consulta  consulta.o cadutil.o

consulta.o: consulta.c cadastro.h
	$(C) -c consulta.c

cadutil.o: cadutil.c cadastro.h
	$(C) -c  cadutil.c
