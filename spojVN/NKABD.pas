var d,j,n,m,s,i:longint;
begin
    readln(n,m);d:=0;
    for j:=n to m do
        begin
            s:=1;
            for i:=2 to trunc(sqrt(j)) do
                if j mod i=0 then
                    begin
                        s:=s+i;
                        if i<>j div i then s:=s+j div i;
                        if s>j then
                            begin
                                inc(d);
                                break;
                            end;
                    end;
        end;
    writeln(d);
end.
