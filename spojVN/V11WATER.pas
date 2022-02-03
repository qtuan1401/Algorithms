uses math;
var a,l,r:array[0..100001] of longint;
    res:int64;i,n,t:longint;
begin
    readln(n);
    for i:=1 to n do
        begin
            read(a[i]);
            l[i]:=max(l[i-1],a[i]);
        end;
    for i:=n downto 1 do r[i]:=max(r[i+1],a[i]);
    for i:=1 to n do
        begin
            t:=min(l[i],r[i]);
            if (t>a[i]) then inc(res,t-a[i]);
        end;
    writeln(res);
end.