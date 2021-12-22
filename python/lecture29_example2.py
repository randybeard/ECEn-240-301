import cmath
import numpy as np

def circuitTF(omega):
    R = 100
    L = 15e-3
    C = 3e-6
    H = 1j*omega*L/((R-omega**2*R*L*C)+1j*omega*L)
    HPolar = cmath.polar(H)
    Hmag = HPolar[0]
    Hangle = HPolar[1] * 180/np.pi
    return Hmag, Hangle

omega1 = 1000
Hmag1, Hangle1 = circuitTF(omega1)
mag1 = 100*Hmag1
angle1 = Hangle1
foo=1

