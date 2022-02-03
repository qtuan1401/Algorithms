var n,i,j,vt:longint;s:int64;
begin
    readln(n);
    if n=1 then
        begin
            writeln('1');
            exit;
        end;
    s:=1;
    vt:=1;
    for i:=2 to 447 do
        begin
            s:=(s div i+1)*i;
            inc(vt);
            if vt=n then
                begin
                    writeln(s);
                    exit;
                end;
            for j:=1 to i-1 do
                begin
                    s:=s+i;
                    inc(vt);
                    if vt=n then
                        begin
                            writeln(s);
                            exit;
                        end;
                end;
        end;
end.



