R = 1;
L = 570e-6;  % 570 mu H
f1 = 960e3;  % 960kHz (KOVO)
C1 = 1/L/((2*pi*f1)^2);
f2 = 1160e3;  % 1160kHz (KSL)
C2 = 1/L/((2*pi*f2)^2);
f3 = 1450e3;  % 1450kHz (KEYY)
C3 = 1/L/((2*pi*f3)^2);


sys1 = tf([1/C1, R/L/C1],[1, R/L, 1/L/C1]);
sys2 = tf([1/C2, R/L/C2],[1, R/L, 1/L/C2]);
sys3 = tf([1/C3, R/L/C3],[1, R/L, 1/L/C3]);
[mag1,phase1,wout] = bode(sys1);
[mag2,phase2,wout] = bode(sys2);
[mag3,phase3,wout] = bode(sys3);

figure(1), clf
    semilogx(wout, 20*log10(squeeze(mag1)), '-b', 'LineWidth',2)
    hold on
    semilogx(wout, 20*log10(squeeze(mag2)), '-k', 'LineWidth',2)
    semilogx(wout, 20*log10(squeeze(mag3)), '-r', 'LineWidth',2)
    grid on
    ylabel('20 log_{10}|H(\omega)|')
    xlabel('log_{10}|\omega|')
    title('Bode Plot')
