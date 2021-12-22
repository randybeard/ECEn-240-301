omega1 = 1000;
[Hmag1, Hangle1] = circuitTF(omega1);
mag1 = 100*Hmag1
angle1 = Hangle1

function [Hmag, Hangle] = circuitTF(omega)
    R = 100;
    L = 15e-3;
    C = 3e-6;
    H = j*omega*L/((R-omega^2*R*L*C)+j*omega*L);
    Hmag = abs(H);
    Hangle = angle(H) * 180/pi;
end