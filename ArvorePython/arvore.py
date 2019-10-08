
def indexaCadastro(nomeArquivo, nomeIndice):

	
	arq = open(nomeArquivo, "rb")
	ndx = open(nomeIndice, "w")

	fpos = arq.tell()
	linha = arq.readline()
	while(linha):
		ndx.write(str(fpos)+","+str(linha).split('|')[2]+"\n") ### posicao e nome
		fpos = arq.tell()
		linha = arq.readline()




class No:
	def __init__(self, indice=0, nome=''):
		self.nome=nome
		self.indice=indice
		self.fD = None
		self.fE = None
	def insere(self,indice,nome):
		if(self.nome==''):
			self.nome = nome
			self.indice=indice
			return
		if(self.nome < nome):
			if( self.fD==None ):
				self.fD = No(indice,nome)
			else:
				self.fD.insere(indice,nome)
		else:
			if( self.fE==None ):
				self.fE = No(indice,nome)
			else:
				self.fE.insere(indice,nome)
	def percorreEmOrdem(self):
		if self.fE:
			self.fE.percorreEmOrdem()
		print(self.nome)
		if self.fD:
			self.fD.percorreEmOrdem()
		
	def carregaIndice(self, nomeindice):
		arq = open(nomeindice)
		linha = arq.readline()
		while(linha):
			self.insere(linha.split(',')[0],linha.split(',')[1] )
			linha = arq.readline()




















