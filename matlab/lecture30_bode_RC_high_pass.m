R = 1e3;
C = 1e-3;
sys = tf([R*C, 0],[R*C 1]);
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
  
print -dpng 'lecture30_RC_high_pass.png'
    