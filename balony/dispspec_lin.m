

function dispspec_lin(x, fs)

    f = linspace(-fs/2,fs/2, length(x));

    x=fftshift((abs(fft(x)/length(x))));
  
    plot(f,x);          
    xlabel('F [Hz]');
    ylabel('Y');   
    title(['Spectrum of ' inputname(1)]);


end
