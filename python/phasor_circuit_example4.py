import cmath
import numpy as np

def parallel(Z1, Z2):
    Zeq = Z1 * Z2 / (Z1 + Z2)
    return Zeq

v1_magnitude = 10
v1_phase = 0*np.pi/180
V1 = cmath.rect(v1_magnitude, v1_phase)
v2_magnitude = 100
v2_phase = -90*np.pi/180
V2 = cmath.rect(v2_magnitude, v2_phase)
Z1 = 50
Z2 = -1j/50000/9e-6
Z3 = 1j*50000*100e-6
Z4 = 20
Ieq = I1 - V2/Z4
Zeq = parallel(Z1, parallel(Z2, parallel(Z3, Z4)))
V0 = Ieq * Zeq
V0_polar = cmath.polar(V0)
v0_magnitude = V0_polar[0]
v0_phase = V0_polar[1] * 180/np.pi
foo = 1