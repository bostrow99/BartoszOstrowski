classdef Response

    properties
        H;
        h;
        fs;
    end

    methods

        function obj = Response(fileName,mode,fs_)
            
            if mode == "f" %file
                [hTemp, obj.fs]=audioread(fileName);
                obj.h = hTemp(:,1);
                obj.H = fft(obj.h); 

            elseif mode == "t" %table
                obj.h = fileName;
                obj.H = fft(obj.H);
                obj.fs = 44100;

                if nargin == 3
                    obj.fs = fs_;
                end

            elseif mode == "b" %baloons
                [reverbTemp, obj.fs]=audioread(fileName);
                reverbTemp=reverbTemp(:,1);
                lengthReverbTemp = length(reverbTemp);
    
    
                [testTemp, ~]=audioread("przed wydzialem/test3.wav");
                testTemp = testTemp(:,1);
                lengthTestTemp = length(testTemp);
                testTemp(end:end+lengthReverbTemp,1)=0;
                reverbTemp(end:end+lengthTestTemp,1)=0;
                
                obj.H = extract_reverb(testTemp,reverbTemp,15);
                obj.h = ifft(obj.H);
            end
        end

        function spectrum(obj,lin_or_dec)
            
            if lin_or_dec == "lin"
                
                f = linspace(-obj.fs/2,obj.fs/2, length(obj.H));
                x = fftshift(abs((obj.H))/length(obj.H));
              
                plot(f,x);          
                xlabel('F [Hz]');
                ylabel('Amplitude');   
                title(['Spectrum of ' inputname(1)]);

            elseif lin_or_dec == "dec"

                f = linspace(-obj.fs/2,obj.fs/2, length(obj.H));        
                x=fftshift(20*log10(abs(obj.H)/length(obj.H)));

                plot(f,x);               
                xlabel('F [Hz]');
                ylabel('Amplitude [dB]');
                title(['Spectrum of ' inputname(1)]);
     
            end

        end

        function time(obj,time)
            
            if nargin == 2 && time == "t"
                t = (0:length(obj.h)-1)/obj.fs;            
               
                plot(t,obj.h);               
                xlabel('time [s]');
                ylabel('Amplitude');
            
            elseif nargin == 1 
                plot(obj.h);               
                xlabel('sample number');
                ylabel('Amplitude');

            end

        end

    end

end