

function dispspec_db(x,fs)

        f = linspace(-fs/2,fs/2, length(x));

        x=fftshift(20*log10(abs(fft(x)/length(x))));
        plot(f,x);               
        xlabel('F [Hz]');
        ylabel('Y [dB]');
        title(['Spectrum of ' inputname(1)]);
        
end
