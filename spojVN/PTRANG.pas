uses math;
var n,l,i,j,s,hs:longint;
    w,f:Array[0..1000000] of longint;
begin
    readln(n,l);
    for i:=1 to n do read(w[i]);
    for i:=1 to n do
        begin
            s:=l-w[i];
            f[i]:=high(f[i]);
            for j:=i-1 downto 0 do
                begin
                    if (s>=0) then
                        begin
                            hs:=max(f[j],s);
                            f[i]:=min(f[i],hs);
                        end
                    else break;
                    dec(s,w[j]);
                end;
        end;
    writeln(f[n]);
end. 	