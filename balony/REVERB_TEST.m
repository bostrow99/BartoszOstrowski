close all;
clear all;
del=20000;

%% Wczytywanie plik�w i przycinanie

[reverb1,fs]=audioread("gg aula/test5.wav");
reverb1=reverb1(:,1);

[reverb2,fs]=audioread("korytarz/test2.wav");
reverb2=reverb2(:,1);

[reverb3,fs]=audioread("audytorium centralne/test2.wav");
reverb3=reverb3(:,1);

[test,fs]=audioread("przed wydzia�em/test2.wav");
test=test(3001:243000,:);
test=test(:,1);
test(del:end,1)=zeros(length(test)-del+1,1);

[guitar,fs]=audioread("guitar.wav");

test = trimmer(test, reverb1);
reverb2 = trimmer(reverb2, reverb1);
reverb3 = trimmer(reverb3, reverb1);
guitar = trimmer(guitar, reverb1);




%% Wykres przebieg�w czasowych balon�w

figure();
subplot(2,2,1);
plot(reverb1);
title("Gmach g��wny")

subplot(2,2,2);
plot(reverb2);
title("Korytarz skrzyd�o C pi�tro 4")

subplot(2,2,3);
plot(reverb3);
title("Audytorium centralne EiTI")

subplot(2,2,4);
plot(test);
title("Przed wydzia�em")

%% Kalkulacje

X=fft(test);
G=(fft(guitar));
Y1=(fft(reverb1));
Y2=(fft(reverb2));
Y3=(fft(reverb3));
eps=10;
H1=extract_reverb(test,reverb1,eps);    
H2=extract_reverb(test,reverb2,eps);  
H3=extract_reverb(test,reverb3,eps); 
G1R=H1.*G;
G2R=H2.*G;
G3R=H3.*G;

guitar1R=ifft(G1R);
guitar2R=ifft(G1R);
guitar3R=ifft(G3R);

%%
Hd = LowPass;
guitar1RLP = filter(Hd,guitar1R);
guitar2RLP = filter(Hd,guitar2R);
guitar3RLP = filter(Hd,guitar3R);

%% Spectrogram
figure();
subplot(2,2,1);
plot(psd(spectrum.periodogram,reverb1,'Fs',44100,'NFFT',length(reverb1)));
set(gca,"ylim",[-90,-60])
subplot(2,2,2);
plot(psd(spectrum.periodogram,reverb2,'Fs',44100,'NFFT',length(reverb2)));
set(gca,"ylim",[-90,-60])
subplot(2,2,3);
plot(psd(spectrum.periodogram,reverb3,'Fs',44100,'NFFT',length(reverb3)));
set(gca,"ylim",[-90,-60])
subplot(2,2,4);
plot(psd(spectrum.periodogram,test,'Fs',44100,'NFFT',length(test)));
set(gca,"ylim",[-90,-60])

%% Wykresy widma

figure();
subplot(2,2,1);
plot(fftshift(abs(Y1)));
title("Gmach g��wny FFT")
subplot(2,2,2);
plot(fftshift(abs(Y2)));
title("Korytarz skrzyd�o C pi�tro 4 FFT")
subplot(2,2,3);
plot(fftshift(abs(Y3)));
title("Audytorium centralne EiTI")
subplot(2,2,4);
plot(fftshift(abs(X)));
title("Przed wydzia�em FFT")

%% Wykresy echa

figure();
subplot(3,1,1);
plot(fftshift(abs(H1)));
title("Pog�os FFT z Gmach g��wny")
subplot(3,1,2);
plot(fftshift(abs(H2)));
title("Pog�os FFT z Korytarz skrzyd�o C pi�tro 4 FFT")
subplot(3,1,3);
plot(fftshift(abs(H3)));
title("Audytorium centralne EiTI") 

%% Spectrogram widma gitary 

figure();
subplot(2,2,1);
plot(psd(spectrum.periodogram,guitar1R,'Fs',44100,'NFFT',length(guitar1R)));
set(gca,"ylim",[-80,-15])
subplot(2,2,2);
plot(psd(spectrum.periodogram,guitar2R,'Fs',44100,'NFFT',length(guitar2R)));
set(gca,"ylim",[-80,-15])
subplot(2,2,3);
plot(psd(spectrum.periodogram,guitar3R,'Fs',44100,'NFFT',length(guitar3R)));
set(gca,"ylim",[-70,-20])
subplot(2,2,4);
plot(psd(spectrum.periodogram,guitar,'Fs',44100,'NFFT',length(guitar)));
set(gca,"ylim",[-90,-30])
%% Wykresy widma gitary 

figure();
subplot(2,2,1);
plot(fftshift(abs(G1R)));
title("Gitara + Pog�os FFT z Gmach g��wny")
subplot(2,2,2);
plot(fftshift(abs(G2R)));
title("Gitara + Pog�os FFT z Korytarz skrzyd�o C pi�tro 4 FFT")
subplot(2,2,3);
plot(fftshift(abs(G3R)));
title("Gitara + Audytorium centralne EiTI") 
subplot(2,2,4);
plot(fftshift(abs(G)));
title("Gitara FFT") 


%% Wykresy gitary

figure();
subplot(2,2,1);
plot(guitar1R);
title("Gitara + Pog�os z Gmach g��wny")
subplot(2,2,2);
plot(guitar2R);
title("Gitara + Pog�os z Korytarz skrzyd�o C pi�tro 4 FFT")     
subplot(2,2,3);
plot(guitar3R);
title("Gitara + Audytorium centralne EiTI")
subplot(2,2,4);
plot(guitar);
title("Gitara")     

%%
sound(guitar,44100);
pause(6);
%%
sound(guitar1R,44100);
pause(6);
%%
sound(guitar2R,44100);
pause(6);
%%
sound(guitar3R,44100);

%%

sound(guitar,44100);
pause(3);
sound(guitar1RLP,44100);
pause(6);
sound(guitar2RLP,44100);
pause(6);
sound(guitar3RLP,44100);

