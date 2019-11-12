


class No:
	def __init__(self, n, i):
		self.nome=n
		self.indice=i
		self.noE = None
		self.noD = None
	def insereNo(self, no):
		if no.nome > self.nome:
			if self.noD:
				self.noD.insereNo(no)
			else:
				self.noD= no
		else:
			if self.noE:
				self.noE.insereNo(no)
			else:
				self.noE= no
	def acha(self, nomeB):
		nomeB = nomeB.upper()
		if self.nome == nomeB:
		        return self
		if self.nome > nomeB:
			if not self.noE: return None
			return self.noE.acha(nomeB)
		else:
			if not self.noD: return None
			return self.noD.acha(nomeB)
	def achaPadrao(self, padrao):
		listaR = []
		padrao = padrao.upper()
		self.achaPadraoNo(padrao,listaR)
		return listaR
	def achaPadraoNo(self,padrao, liR):
		if self.noE: 
			self.noE.achaPadraoNo(padrao,liR)	
		if padrao in self.nome:
			liR.append(self.indice)
			#print(self.nome)
		if self.noD: 
			self.noD.achaPadraoNo(padrao, liR)

def imprimeReg(indice):
	#global inf
	inf.seek(it)
	p = str(inf.readline()).split('|')
	print(p[2],"\t",p[3],"\t",p[12])
def imprimeRegList(l):
	for it in l: imprimeReg(it)
		



inf = open("../data/cadastro2019.csv",encoding='l1')
#try: 
#	indf = open("../data/cadpy.ndx","r")
#except: 
#	li = inf.readline()
#	fpos = inf.tell()
#	li = inf.readline()
#	while(li):
#		indf.write( str(li).split('|')[2] + ' '+str(fpos)+"\n")

li = inf.readline()
fpos = inf.tell()
li = inf.readline()

arvore = None

while(li):
	
	#indf.write( str(li).split('|')[2] + ' '+str(fpos)+"\n")
	novoNo = No( str(li).split('|')[2],fpos )
	if not arvore:
		arvore = novoNo
	else:
		arvore.insereNo(novoNo)
	
	fpos = inf.tell()
	li = inf.readline()













