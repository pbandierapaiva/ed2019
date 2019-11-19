#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Nov 16 12:17:13 2019

@author: paiva
"""

import pandas as pd

cad = pd.read_csv("../data/cadastro2019.csv", encoding='latin-1',dtype='str', sep='|')

cad.describe()

# quais colunas?
cad.columns


# recuperar um registro
cad[ cad['NOME']=='PAULO BANDIERA PAIVA' ][ ['NOME','ORG_LOTACAO'] ]

# tem duplicação neste campo?
cad['Id_SERVIDOR_PORTAL'].describe()

# quais são duplicados?
dup = cad.duplicated('Id_SERVIDOR_PORTAL')
#inverte o dup, quais não são duplicados?
ndup = dup.apply( lambda x: not(x) )

# df com nomes únicos
cadu = cad[naodup]

cadu = cad.drop_duplicates(['NOME'])

poruf =cadu.groupby(['UF_EXERCICIO'])
poruf.size()

unicossp = poruf.get_group('SP')


caduforg =cadu.groupby(['UF_EXERCICIO','ORG_EXERCICIO'])

# todos os registros de servidores federais de SP, com duplicatas
servsp = cad[cad['UF_EXERCICIO']=='SP']

# salva objeto num arquivo
servsp.to_pickle('servsp.gz',compression='gzip')

# lê objeto de arquivo
sp = pd.read_pickle('servsp.gz')



