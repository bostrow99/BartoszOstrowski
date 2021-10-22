function x = plotspec(x,fs)

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

x=fftshift(20*log10(abs(fft(x)/length(x))));
ylabel('Y [dB]');
plot(f,x);
    hold off;
    
end