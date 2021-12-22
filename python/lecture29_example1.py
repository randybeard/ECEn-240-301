import cmath
import numpy as np

def circuitTF(omega):
    R = 20
    L = 15e-3
    H = 1j*omega*L/(R+1j*omega*L)
    HPolar = cmath.polar(H)
    Hmag = HPolar[0]
    Hangle = HPolar[1] * 180/np.pi
    return Hmag, Hangle

omega1 = 100
Hmag1, Hangle1 = circuitTF(omega1)
omega2 = 15000
Hmag2, Hangle2 = circuitTF(omega2)
mag1 = 5*Hmag1
angle1 = Hangle1
mag2 = 15*Hmag2
angle2 = Hangle2
foo=1

