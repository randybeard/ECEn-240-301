load sonar

figure(1)
    clf, hold on
    plot(sonarRaw(100:end))
    ylabel('Duration in microseconds')
    xlabel('time')
    print -dpng sonar_raw.png

figure(2)
    clf, hold on
    plot(sonarDistanceRaw(100:end))
    ylabel('Distance in cm')
    xlabel('time')
    print -dpng sonar_distance_raw.png
    
figure(3)
    clf, hold on
    plot(sonarSmoothed(100:end))
    ylabel('Distance in cm')
    xlabel('time')
    print -dpng sonar_smoothed.png    