


class No:
	def __init__(self, n, i):
		self.nome=n
		self.indice=i
		self.noE = None
		self.noD = None
		self.listaResp =[]
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
		self.listaResp =[]
		padrao = padrao.upper()
		self.achaPadraoNo(padrao)
		for it in self.listaResp:
			inf.seek(it.indice)
			p = str(inf.readline()).split('|')
			print(p[2],p[3],p[12])
	def achaPadraoNo(self,padrao):
		if padrao in self.nome:
			self.listaResp.append(self)
			print(self.nome)
		if self.noE: 
			self.noE.achaPadraoNo(padrao)	
		if self.noD: 
			self.noD.achaPadraoNo(padrao)


inf = open("../data/cadastro2019.csv",encoding='l2')
#indf = open("../data/cadpy.ndx","w")

li = inf.readline()
fpos = inf.tell()
li = inf.readline()

arvore = None

while(li):
	
	#indf.write( str(li).split('|')[2] + ' '+str(fpos)+"\n")
	novoNo = No( str(li).split('|')[2],fpos )
	if not arvore:
		arvore = novoNo
		inicio=False
	else:
		arvore.insereNo(novoNo)
	
	fpos = inf.tell()
	li = inf.readline()

