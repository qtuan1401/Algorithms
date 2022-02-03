uses math;
var f:array[0..3001,0..3001] of longint;
    i,j,n:longint;res,s,s1:ansistring;
begin
    readln(s);
    n:=length(s);
    for i:=n downto 1 do s1:=s1+s[i];
    for i:=0 to n do f[i,0]:=0;
    for j:=0 to n do f[0,j]:=0;
    for i:=1 to n do
        for j:=1 to n do
            begin
                if s[i]=s1[j] then f[i,j]:=f[i-1,j-1]+1
                    else f[i,j]:=max(f[i-1,j],f[i,j-1]);
            end;
    res:='';
    while (i<>0) and (j<>0) do
        begin
            if s[i]=s1[j] then
                begin
                    res:=s[i]+res;
                    dec(i);
                    dec(j);
                end
                else
                    if f[i,j]=f[i,j-1] then dec(j)
                        else dec(i);
        end;
    writeln(res);
end.