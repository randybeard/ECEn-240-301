sys = tf(1,[1 1]);
[mag,phase,wout] = bode(sys);

figure(1), 
    subplot(2,1,1)
    semilogx(wout, 20*log10(squeeze(mag)), '-b', 'LineWidth',2)
    grid on
    set(gca,'xticklabel',{[]})
    ylabel('20 log_{10}|H(\omega)|')
    xlabel('log_{10}|\omega|')
    title('Bode Plot')

subplot(2,1,2)
    semilogx(wout, squeeze(phase), '-b', 'LineWidth',2)
    grid on 
    set(gca,'xticklabel',{[]})
    ylabel('\angle H(\omega)')
    xlabel('log_{10}|\omega|')
  
print -dpng 'lecture30_lpf_bode.png'
    