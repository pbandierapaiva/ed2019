##################################################################
# Makefile para construção do executável com utilitário make
#
#

C = gcc

consulta: consulta.o cadutil.o listadl.o
	$(C) -o consulta  consulta.o cadutil.o listadl.o

consulta.o: consulta.c cadastro.h
	$(C) -c consulta.c

cadutil.o: cadutil.c cadastro.h
	$(C) -c  cadutil.c

listadl.o: listadl.c listadl.h
	$(C) -c listadl.c
