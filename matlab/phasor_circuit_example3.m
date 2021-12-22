is_magnitude = 8;
is_phase = 0*pi/180;
Is = is_magnitude*cos(is_phase) + j*is_magnitude*sin(is_phase);
Z1 = 10;
Z2 = j*200e3*40e-6;
Z3 = 6;
Z4 = -j/200e3/1e-6;
Z_eq = parallel(parallel(Z1, Z2+Z3), Z4);
V = Is*Z_eq;
v_magnitude = abs(V);
v_phase = angle(V) *180/pi;
Z_eq1 = parallel(Z2+Z3, Z4);
I1 = Is * (Z_eq1/(Z1+Z_eq1));
i1_magnitude = abs(I1);
i1_phase = angle(I1) * 180/pi;
Itmp = Is * (Z1/(Z1+Z_eq1));
I2 = Itmp * (Z4/(Z2+Z3+Z4));
i2_magnitude = abs(I2);
i2_phase = angle(I2) * 180/pi;
I3 = Itmp * ((Z2+Z3)/(Z2+Z3+Z4));
i3_magnitude = abs(I3);
i3_phase = angle(I3) * 180/pi;


function Zeq = parallel(Z1, Z2)
    Zeq = Z1*Z2/(Z1+Z2);
end
