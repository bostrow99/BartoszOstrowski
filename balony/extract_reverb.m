function H = extract_reverb(test,reverb,eps0)
    X = fft(test);
    Y = fft(reverb);
    H=(Y.*conj(X))./(abs(X).^2+eps0); 
  
    H1 = ifft(H);
    H1(end-20000:end,1) = 0 ;
    H = fft(H1);
    
end