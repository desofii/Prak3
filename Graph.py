import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import math

x = np.arange(-5, 5, 0.001)

plt.ylim(0, 10)


plt.plot(x, np.sin(1/(1+np.arctan(np.exp(-x*x)))), label="sin(1/(1+arctg(e^-x^2))^2)")
plt.plot(x,5 - x, label="5-x")
plt.legend()

#plt.plot(x, np.arctan(x))

plt.show()
