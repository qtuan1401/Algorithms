var n,i,d,mid,res,c:longint;
    a,h,f:array[0..100000] of longint;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    h[1]:=1;
    res:=1;
    for i:=2 to n do
        begin
            d:=0;
            c:=res+1;
            while (d+1<>c) do
                begin
                    mid:=(d+c) div 2;
                    if (a[i]<=a[h[mid]]) then c:=mid
                    else d:=mid;
                end;
            h[d+1]:=i;
            if (d=res) then inc(res);
        end;
    writeln(res);
end.