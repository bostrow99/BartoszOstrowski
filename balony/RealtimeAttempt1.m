buforLength = 512;

% Audio imput and output
deviceReader = audioDeviceReader;
deviceReader.Driver = 'ASIO';
deviceReader.Device ='ASIO UX1';
deviceReader.SamplesPerFrame = 1024; 

deviceWriter = audioDeviceWriter('SampleRate',deviceReader.SampleRate);
deviceWriter.Driver = 'ASIO';
deviceWriter.Device = 'ASIO UX1';


%%
deviceReader = audioDeviceReader;
deviceReader.Driver = 'DirectSound';
deviceReader.Device ='Cyfrowy interfejs audio (3 — Line 6 UX1)';

deviceWriter = audioDeviceWriter('SampleRate',deviceReader.SampleRate);
deviceWriter.Driver = 'DirectSound';
deviceWriter.Device = 'Realtek HD Audio 2nd output (Realtek(R) Audio)';

%%

tic
while toc < 60
    x = step(deviceReader);
    plot(x)
    ylim([-1 1])
    xlim([0 1024])
    drawnow
end

%%

tic
while toc < 60
    x = step(deviceReader);
    y=x;
    step(deviceWriter,y);
    plot(x)
    ylim([-1 1])
    xlim([0 1024])
    drawnow
end
