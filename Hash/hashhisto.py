import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import pandas as pd 

x = pd.read_csv("output", header=None)

plt.hist(x[0],1000)



