close all;
clear all;
del=20000;

%% Wczytywanie plik?w i przycinanie

[reverb1temp,~]=audioread("gg aula/test5.wav");
reverb1=reverb1temp(:,1);

[reverb2temp,~]=audioread("korytarz/test2.wav");
reverb2=reverb2temp(:,1);

[reverb3temp,~]=audioread("audytorium centralne/test2.wav");
reverb3=reverb3temp(:,1);

[test,~]=audioread("przed wydzialem/test2.wav");
test=test(3001:243000,:);
test=test(:,1);
test(del:end,1)=zeros(length(test)-del+1,1);

[guitartemp,fs]=audioread("guitar.wav");
guitar=guitartemp;

guitar1 = trimmer2(guitar,reverb1);
guitar2 = trimmer2(guitar,reverb2);
guitar3 = trimmer2(guitar,reverb3);
reverb1t = trimmer2(reverb1,guitar);
reverb2t = trimmer2(reverb2,guitar);
reverb3t = trimmer2(reverb3,guitar);
test1 = trimmer(test, reverb1t);
test2 = trimmer(test, reverb2t);
test3 = trimmer(test, reverb3t);
%% Kalkulacje

G1=(fft(guitar1));
G2=(fft(guitar2));
G3=(fft(guitar3));
eps=15;
H1=extract_reverb(test1,reverb1t,eps);    
H2=extract_reverb(test2,reverb2t,eps);  
H3=extract_reverb(test3,reverb3t,eps); 
G1R=H1.*G1;
G2R=H2.*G2;
G3R=H3.*G3;

guitar1R=ifft(G1R);
guitar2R=ifft(G1R);
guitar3R=ifft(G3R);


%%
xcr=(xcorr(reverb2(:,1),reverb2(:,1)));
tc=[(-length(reverb2(:,1))+1):(length(reverb2(:,1))-1)]./fs;
plot(tc*300,20*log10(abs(xcr)))
xlabel('[m]')
ylabel('dB')

%% Wykres przebieg?w czasowych balon?w

figure();
subplot(2,2,1);
plot(reverb1);
title("Gmach g??wny")

subplot(2,2,2);
plot(reverb2);
title("Korytarz skrzyd?o C pi?tro 4")

subplot(2,2,3);
plot(reverb3);
title("Audytorium centralne EiTI")

subplot(2,2,4);
plot(test);
title("Przed wydzia?em")


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
title("Gmach g??wny FFT")
subplot(2,2,2);
plot(fftshift(abs(Y2)));
title("Korytarz skrzyd?o C pi?tro 4 FFT")
subplot(2,2,3);
plot(fftshift(abs(Y3)));
title("Audytorium centralne EiTI")
subplot(2,2,4);
plot(fftshift(abs(X)));
title("Przed wydzia?em FFT")

%% Wykresy echa

figure();
subplot(3,1,1);
plot(fftshift(abs(H1)));
title("Pog?os FFT z Gmach g??wny")
subplot(3,1,2);
plot(fftshift(abs(H2)));
title("Pog?os FFT z Korytarz skrzyd?o C pi?tro 4 FFT")
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
title("Gitara + Pog?os FFT z Gmach g??wny")
subplot(2,2,2);
plot(fftshift(abs(G2R)));
title("Gitara + Pog?os FFT z Korytarz skrzyd?o C pi?tro 4 FFT")
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
title("Gitara + Pog?os z Gmach g??wny")
subplot(2,2,2);
plot(guitar2R);
title("Gitara + Pog?os z Korytarz skrzyd?o C pi?tro 4 FFT")     
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

%%
test_Oliwii=varWindow(guitar3R,0.05e-2,5000);
plot(test_Oliwii)
hold on
plot(guitar3R)
hold off
%%
temp=find(test_Oliwii>0);

end_value=temp(1);

guitar_noisegate=guitar3R(1:end_value);
plot(guitar_noisegate)
sound(guitar_noisegate,fs)
%%

guitar3Rtemp=guitar3R(70000:end);
plot(guitar3Rtemp);
%%
dispspec_lin(guitar3Rtemp,fs)

%%

F200 = 10*fft(guitar3R(7e4:end));

%guitarR3F = filter(F200, guitar3R);
guitar3RF = bandstop(guitar3R, [190 210],fs);
guitar3RF2 = bandstop(guitar3RF, [190 210],fs);