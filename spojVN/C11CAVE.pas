var a:array[0..1000000] of int64;
    n,i,k,h:longint;
    res,l:int64;
begin
    readln(n,h);
    for i:=1 to n do
        begin
            readln(k);
            if (i mod 2=1) then
                begin
                    inc(a[1]);
                    dec(a[k+1]);
                end
            else inc(a[h-k+1]);
        end;
    res:=a[1];
    l:=1;
    for i:=2 to h do
        begin
            a[i]:=a[i]+a[i-1];
            if res>a[i] then
                begin
                    res:=a[i];
                    l:=1;
                end
            else if (res=a[i]) then inc(l);
        end;
    writeln(res,' ',l);
end.