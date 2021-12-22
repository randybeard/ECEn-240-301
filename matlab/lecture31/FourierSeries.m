classdef FourierSeries
    properties
        a_0  % DC Fourier coefficients
        a_pos % positive Fourier coefficents
        a_neg % negative Fourier coefficient
        N  % number of Fouries coefficent is 2N+1
        T  % period
        time
    end
    methods
         %---constructor--------------------------------
        function self = FourierSeries(x, N)
            self.N = N;
            self.time = x.time;
            self.T = x.T;
            % compute Fourier coefficients for real signals
            self.a_0 = (1/x.T)*self.integrate(x.signal, x.Ts);
            for k=1:N
                self.a_pos(k) = (1/x.T)*self.integrate(x.signal.*exp(-j*2*pi/x.T*k*x.time), x.Ts);
                self.a_neg(k) = self.a_pos(k)'; % neg coef are complex conjugate of pos coefficients
            end
        end
        function I = integrate(self, signal, Ts)
            % Riemann integration of signal
            I = 0;
            for i=1:length(signal)
                I = I + Ts*signal(i);
            end
        end
        function plotCoefficients(self)
            idx = [-self.N:-1, 0, 1:self.N];
            magA = [fliplr(abs(self.a_neg)), abs(self.a_0), abs(self.a_pos)]; % magnitude of coefficients
            angleA = [fliplr(angle(self.a_neg)), angle(self.a_0), angle(self.a_pos)]; % phase of coefficients
            subplot(211), stem(idx, magA)
            subplot(212), stem(idx, angleA)
        end
        function out=approxSignal(self, K)
            % approximate signal with 2*K+1 coefficents in Fourier series
            if K > self.N
                disp('Need to instantiate class with more coefficients')
                out = [];
            else
                % compute the approximate signal with 2*K+1 terms
                out = self.a_0*ones(1,length(self.time)); % DC term
                for k = 1:K
                    out = out + self.a_pos(k)*exp(j*2*pi/self.T*k*self.time); % positive coefficients
                    out = out + self.a_neg(k)*exp(-j*2*pi/self.T*k*self.time); % negative coefficients
                end
            end
        end
    end
end
       