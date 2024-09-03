# test matplotlib

import matplotlib.pyplot as plt
import numpy as np

t = np.array([0,1,2,3,4,5,6])
x = np.array([0,-2,5,2,4,5,6])

plt.plot(t,x)
plt.show()