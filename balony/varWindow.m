function result=varWindow(signal,th,win)
    result=ones(length(signal),1);
    for N=win+1:length(signal)-win
        if var(signal(N-win:N+win))<th
            result(N)=0;
        end 
    end 
    
end 