clear all

i1_magnitude = 10;
i1_phase = 0*pi/180;
v2_magnitude = 100;
v2_phase = -90*pi/180;
I1 = i1_magnitude*cos(i1_phase) + j*i1_magnitude*sin(i1_phase);
V2 = v2_magnitude*cos(v2_phase) + j*v2_magnitude*sin(v2_phase);
Z1 = 50;
Z2 = -j/50000/9e-6;
Z3 = j*50000*100e-6;
Z4 = 20;

Ieq = I1-V2/Z4;
Zeq = parallel(parallel(parallel(Z1, Z2), Z3), Z4);
V0 = Ieq*Zeq;
v0_magnitude = abs(V0);
v0_phase = angle(V0) *180/pi;

function Zeq = parallel(Z1, Z2)
    Zeq = Z1*Z2/(Z1+Z2);
end
