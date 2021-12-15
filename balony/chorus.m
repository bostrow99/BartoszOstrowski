infile='guitar.wav';
outfile='out_chorus.wav';
% current sample is 11kHz so 0-3 ms is 0 - 33 samples
% read the sample waveform
[x,Fs] = audioread(infile);
% normalize x to +/- 1 amplitude
x = x ./ (max(abs(x)));
samples = length(x);
% parameters to vary the effect %
min_time_delay=0.010; % 10ms min delay in seconds
max_time_delay=0.025; % 25ms max delay in seconds
% nb_effects = 4; % assume we do 4 delayed versions of the signal that will be summed 
rate=[0.1 0.05 0.05 0.05] ; %rate of flange in Hz (as many as chorus effects)
nb_effects = length(rate); % assume we do 4 delayed versions of the signal that will be summed in the final section
% amplitude is now a vector
amp=[0.7 0.6 0.5 0.4 0.3];; % suggested coefficient from page 71 DAFX; 
% Nb the first value applies to x and the remaining values apply to the 4
% delayed versions of x) so make sure this vector has length = nb_effects  +1
index=(1:samples)';
% sin reference to create oscillating delay
sin_ref = (sin(2*pi*index*(rate/Fs)))';    % sin(2pi*fa/fs);  % make sure this is a matrix dimensins =  (nb_effects , samples)
% sin_ref = 0.5*(1+sin(2*pi*index*(rate/Fs)))';    % sin(2pi*fa/fs);  % make sure this is a matrix dimensins =  (nb_effects , samples)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
min_samp_delay=round(min_time_delay*Fs); %convert delay in ms to min delay in samples
max_samp_delay=round(max_time_delay*Fs); %convert delay in ms to max delay in samples
y = zeros(samples,1);       % create empty out vector
y(1:max_samp_delay)=x(1:max_samp_delay); % to avoid referencing of negative samples
% amp=0.7; % suggested coefficient from page 71 DAFX
% for each sample
for i = (max_samp_delay+1):length(x)
    cur_sin=abs(sin_ref(:,i));    %abs of current sin val 0-1
    cur_delay=ceil(cur_sin*max_samp_delay);  % generate delay from 1-max_samp_delay and ensure whole number  
    % add the amp weigthed multiple delayed x values
    y(i) = amp(1)*x(i) + sum(amp(2:nb_effects+1)'.*x(i-cur_delay));   % add all 4 delayed sample (in one shot !)
end
% write output
% normalize y to +/- 1 amplitude
y = y ./ (max(abs(y)));
audiowrite(outfile, y, Fs);
figure(1)
hold on
plot(x,'r');
plot(y,'b');
title('Chorus and original Signal');
hold off;
chorus1 = Response("out_chorus.wav","f");
guitar1 = Response("guitar.wav","f");

figure;
subplot(1,2,1);
chorus1.time("t");
hold on;
guitar1.time("t");
hold off;
legend("Gitara z chorusem","Gitara bez chorusa",'FontSize', 18);
title("Przebiegi czasowe", 'FontSize', 24)
subplot(1,2,2);
chorus1.spectrum("dec");
hold on;
guitar1.spectrum("dec");
hold off;
legend("Gitara z chorusem","Gitara bez chorusa",'FontSize', 18);
title("Widmo", 'FontSize', 24)
