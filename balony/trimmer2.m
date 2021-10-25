function x = trimmer2(guitar,reverb)
x = guitar;
x(end:end+length(reverb),1)=0;
end