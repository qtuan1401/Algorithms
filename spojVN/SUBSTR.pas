var i,n,m,j:longint;
    a,b:ansistring;
    t:array[1..1000000] of longint;
begin
    readln(a);
    readln(b);
    n:=length(a);
    m:=length(b);
    j:=0;t[1]:=0;
    for i:=2 to m do
        begin
            while (j>0) and (b[i]<>b[j+1]) do j:=t[j];
            if (b[i]=b[j+1]) then inc(j);
            t[i]:=j;
        end;
    j:=0;
    for i:=1 to n do
        begin
            while (j>0) and (a[i]<>b[j+1]) do j:=t[j];
            if (a[i]=b[j+1]) then inc(j);
            if (j=m) then
                begin
                    write(i-j+1,' ');
                    j:=t[m];
                end;
        end;
end.