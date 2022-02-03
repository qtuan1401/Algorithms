var s:ansistring;x,y:char;t,d:int64;i:longint;
begin
    readln(s);
    readln(x,y);
    t:=0;d:=0;
    if x=y then
        begin
            for i:=1 to length(s) do
                if s[i]=x then d:=d+1;
            writeln(d*(d-1) div 2);
        end
    else
        begin
            t:=0;d:=0;
            for i:=length(s) downto 1 do
                begin
                    if s[i]=y then d:=d+1;
                    if s[i]=x then t:=t+d;
                end;
            writeln(t);
        end;
end.