uses math;
var a,b,c,f:array[1..10000] of longint;
    res:int64;n,i,j:longint;
procedure swap(var x,y:longint);
begin
    x:=x xor y;
    y:=x xor y;
    x:=x xor y;
end;
procedure quicksort(l,r:longint);
var mid,tmp,i,j:longint;
begin
    i:=l;
    j:=r;
    mid:=a[(l+r) div 2];
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if not(i>j) then
            begin
                if (i<>j) then
                    begin
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);
                        swap(c[i],c[j]);
                    end;
                inc(i);
                dec(j);
            end;
    until i>j;
    if (l<j) then quicksort(l,j);
    if (i<r) then quicksort(i,r);
end;
begin
    readln(n);
    for i:=1 to n do
        begin
            readln(a[i],b[i]);
            c[i]:=b[i]-a[i];
        end;
    quicksort(1,n);
    for i:=1 to n do
        begin
            f[i]:=c[i];
            for j:=1 to i-1 do
                if (a[i]>=b[j]) and (f[i]<f[j]+c[i]) then f[i]:=f[j]+c[i];
            res:=max(res,f[i]);
        end;
    writeln(res);
end.