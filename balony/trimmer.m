function x = trimmer(signal, ref)

if length(signal) > length(ref)
    x = signal(1:length(ref));
else
    x = signal;
    x(end+1:end+(length(ref)-length(signal))) = 0;
end