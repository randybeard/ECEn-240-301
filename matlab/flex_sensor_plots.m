load flex_sensor

figure(1), 
    plot(angle_raw) 
    print -dpng angle_raw.png
figure(2)
    plot(angle_calibrated)
    print -dpng angle_calibrated.png
figure(3)
    plot(angle_smoothed)
    print -dpng angle_smoothed.png