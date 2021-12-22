classdef signalGenerator < handle
    properties
        T  % period
        Ts % sample rate
        time
        signal
    end
    methods
         %---constructor--------------------------------
        function self = signalGenerator(period)
            self.T = period;
            self.Ts = period/1000;  % sample rate for integration and plotting
            self.time = 0:self.Ts:period;
            self.signal = zeros(1,length(self.time));
        end
        %---------------------e--------------
        function self = pulse(self, Amplitude, width)
            I = floor(width/self.T*length(self.time));
            self.signal(1:I) = Amplitude;
        end
        %-----------------------------------
        function self = hat(self, Amplitude)
            L = floor(length(self.time)/2);
            for k=1:L
                self.signal(k) = 2*Amplitude/self.T*self.time(k);
            end
            for k=L+1:length(self.time)
                self.signal(k) = -2*Amplitude/self.T*self.time(k) + 2*Amplitude;
            end
        end
        %-----------------------------------
        function self = ramp(self, Amplitude, width)
            L = floor(length(self.time)*width/self.T);
            for k=1:L
                self.signal(k) = Amplitude/width*self.time(k);
            end
        end
    end
end
       