function result = convolution(fileName1, fileName2, n)
    fileName1Temp = fileName1;
    fileName2Temp = fileName2; 

    file1Length = length(fileName1);
    file2Length = length(fileName2);

    fileName2Temp(end:end+file1Length,1) = 0;
    fileName1Temp(end:end+file2Length,1) = 0;
    
    fileName1FFT = fft(fileName1Temp);
    fileName2FFT = fft(fileName2Temp);

    result_fft = fileName1FFT.* fileName2FFT;
    result = ifft(result_fft);

    if nargin == 3
        if strcmp(n,"n")
        result = result/max(abs(result));
        end
    elseif nargin == 2
        
    end
end