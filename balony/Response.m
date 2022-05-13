classdef Response

    properties

        H;
        h;
        fs;
        
    end

    methods

        function obj = Response(fileName, mode, fs_, fileName2) 
            if or(nargin == 2, nargin == 3)
                if strcmp(mode,"f")  %file
                    [hTemp, obj.fs]=audioread(fileName);  
                    obj.h = hTemp(:, 1);
                    obj.H = fft(obj.h); 
                elseif strcmp(mode,"t")  %table
                    obj.h = fileName;
                    obj.H = fft(obj.h);
                    obj.fs = 44100;
                    if nargin == 3
                        obj.fs = fs_;
                    end
                end
            elseif strcmp(mode,"b") 

                    [reverbTemp, obj.fs] = audioread(fileName);
                    reverbTemp = reverbTemp(:, 1);
                    lengthReverbTemp = length(reverbTemp);
                    [testTemp, ~] = audioread(fileName2);
                    testTemp = testTemp(:, 1);
                    lengthTestTemp = length(testTemp);
                    testTemp(end:end+lengthReverbTemp, 1) = 0;
                    reverbTemp(end:end+lengthTestTemp, 1) = 0;      
                    obj.H = extract_reverb(testTemp,reverbTemp,15);
                    obj.h = ifft(obj.H);
            end
           % obj.h = obj.h/max(abs(obj.h));
          %  obj.H = fft(obj.h);
        end
        
        function spectrum(obj, lin_or_dec)  
            if strcmp(lin_or_dec, "lin")        
                f = linspace(-obj.fs/2,obj.fs/2, length(obj.H));
                x = fftshift(abs((obj.H))/length(obj.H));         
                plot(f, x);          
                xlabel('F [Hz]');
                ylabel('Amplitude');   
                title(['Spectrum of ' inputname(1)]);
            elseif strcmp(lin_or_dec, "dec")
                f = linspace(-obj.fs/2,obj.fs/2, length(obj.H));        
                x = fftshift(20*log10(abs(obj.H)/length(obj.H)));
                plot(f, x);               
                xlabel('F [Hz]','FontSize', 24);
                ylabel('Amplitude [dB]','FontSize', 24);
                title(['Spectrum of ' inputname(1)],'FontSize', 24);
            end
        end

        function time(obj, time)
            if nargin == 3 && strcmp(time, "t")
                t = (0:length(obj.h)-1)/obj.fs;            
                plot(t,20*log10(abs(obj.h))./max(abs(obj.h)));               
                xlabel('time [s]','FontSize', 24);
                ylabel('Amplitude','FontSize', 24);     
                title(['Time waveform of ' inputname(1)],'FontSize', 24);
            elseif nargin == 1 
                plot(obj.h);               
                xlabel('sample number','FontSize', 24);
                ylabel('Amplitude','FontSize', 24);
                title(['Time waveform of ' inputname(1)],'FontSize', 24);
            end
        end

        function time_norm(obj, lin_or_dec, time)
            if strcmp(lin_or_dec, "lin")

                out = obj.h./max(obj.h);
                e1=envelope(out,int32(1e-3*length(obj.h)),'peak');

            elseif strcmp(lin_or_dec, "dec")
                
                out = 20*log10((abs(obj.h)+1e-5)./max(abs(obj.h)));
                e1=envelope(out,int32(1e-3*length(obj.h)),'peak');

            end

            if nargin == 3 && strcmp(time, "t")
                t = (0:length(obj.h)-1)/obj.fs;            
                plot(t,out);
                hold on;
                plot(t,e1);
                hold off;
                xlabel('time [s]','FontSize', 24);
                ylabel('Amplitude','FontSize', 24);     
                title(['Time waveform of ' inputname(1)],'FontSize', 24);
            elseif nargin == 2 
                plot(out);
                hold on;
                plot(e1);
                hold off;
                xlabel('sample number','FontSize', 24);
                ylabel('Amplitude','FontSize', 24);
                title(['Time waveform of ' inputname(1)],'FontSize', 24);
            end
        end




        function obj = filter(obj, fileName, freq_or_time)
            if strcmp(freq_or_time, "f")
                fileNameTemp = ifft(fileName);
            elseif strcmp(freq_or_time, "t")
                fileNameTemp = fileName;
            end  
            obj.h = conv(obj.h, fileNameTemp);

        end

        function play(obj)
            sound(obj.h,obj.fs);
        end

    end

end