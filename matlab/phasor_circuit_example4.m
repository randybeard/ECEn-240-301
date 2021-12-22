clear all

v1_magnitude = 240;
v1_phase = 53.13*pi/180;
v2_magnitude = 96;
v2_phase = 0*pi/180;
V1 = v1_magnitude*cos(v1_phase) + j*v1_magnitude*sin(v1_phase);
V2 = v2_magnitude*cos(v2_phase) + j*v2_magnitude*sin(v2_phase);
Z1 = j*4000*15e-6;
Z2 = 30;
Z3 = -j/4000/25e-6;
Z4 = 20;

Zeq = parallel(parallel(parallel(Z1, Z2), Z3), Z4);
Ieq = V1/Z1 - V2/Z4;
V0 = Ieq*Zeq;
v0_magnitude = abs(V0);
v0_phase = angle(V0) *180/pi;


function Zeq = parallel(Z1, Z2)
    Zeq = Z1*Z2/(Z1+Z2);
end
