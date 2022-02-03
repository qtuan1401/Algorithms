uses math;
type list=array[0..100000] of longint;
var h,a,f,f1:list;
    i,n,res:longint;
    mid,d,c,tmp:longint;
procedure process(var f:list);
begin
    h[1]:=1;
    res:=1; f[1]:=1;
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
            f[i]:=d+1;
            if (d=res) then inc(res);
        end;
end;
procedure process1(var f:list);
begin
    h[1]:=1;
    res:=1; f[1]:=1;
    for i:=2 to n do
        begin
            d:=0;
            c:=res+1;
            while (d+1<>c) do
                begin
                    mid:=(d+c) div 2;
                    if (a[i]>=a[h[mid]]) then c:=mid
                    else d:=mid;
                end;
            h[d+1]:=i;
            f[i]:=d+1;
            if (d=res) then inc(res);
        end;
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
     for i:=1 to n div 2 do
        begin
            tmp:=a[i];
            a[i]:=a[n-i+1];
            a[n-i+1]:=tmp;
        end;
    process1(f);
    process(f1);
    res:=0;
    for i:=1 to n do
        res:=max(res,f[i]+f1[i]-1);
    writeln(res);
end.
