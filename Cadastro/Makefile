##################################################################
# Makefile para construção do executável com utilitário make
#
#

C = gcc -g

all: consulta consulta-dl

consulta: consulta.o cadutil.o listadl.o
	$(C) -o consulta  consulta.o cadutil.o listadl.o
consulta.o: consulta.c cadastro.h listadl.h cadutil.h
	$(C) -c consulta.c

consulta-dl: consulta-dl.o cadutil.o listadl.o
	$(C) -o consulta-dl  consulta-dl.o cadutil.o listadl.o
consulta-dl.o: consulta-dl.c cadastro.h listadl.h cadutil.h
	$(C) -c consulta-dl.c

cadutil.o: cadutil.c cadastro.h cadutil.h
	$(C) -c  cadutil.c

listadl.o: listadl.c listadl.h
	$(C) -c listadl.c

limpa:
	rm *.o consulta consulta-dl
