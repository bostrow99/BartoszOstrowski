function x = spectrum(x,fs)

figure();
title('Spectrum');
hold on;

if nargin==2
    f = linspace(-fs/2,fs/2, length(x));
    xlabel('F [Hz]');
else
    f = linspace(-length(x)/2, length(x)/2, length(x));
    xlabel('F');
end

x=fftshift(((fft(x)/length(x))));
ylabel('Y [ddfdB]');
plot(f,x);
    hold off;
    
end