R1C1 = 0.01;
R2C2 = 1;
%sys = tf([1,0],[1, 1/R1C1+1/R2C2, 1/R1C1/R2C2]);
sys = tf([R2C2,0],[R1C1*R2C2, R1C1+R2C2, 1]);
[mag,phase,wout] = bode(sys);

figure(1), 
    subplot(2,1,1)
    semilogx(wout, 20*log10(squeeze(mag)), '-b', 'LineWidth',2)
    grid on
    ylabel('20 log_{10}|H(\omega)|')
    xlabel('log_{10}|\omega|')
    title('Bode Plot')

subplot(2,1,2)
    semilogx(wout, squeeze(phase), '-b', 'LineWidth',2)
    grid on 
    ylabel('\angle H(\omega)')
    xlabel('log_{10}|\omega|')
  
print -dpng 'lecture30_bode_band_pass.png'
    