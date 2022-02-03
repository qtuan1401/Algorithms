var a:array[1..200000] of longint;
    b:array[1..200000] of longint;
    dd:array[1..200000] of boolean;
    n,i,dem:longint;
procedure calc(var i,j:longint);
begin
    inc(i);
    dec(j);
end;
procedure swap(var a,b:longint);
begin
        a:=a xor b;
        b:=a xor b;
        a:=a xor b;
end;
procedure quicksort(l,r:longint);
var i,j,mid:longint;
begin
    i:=l;
    j:=r;
    mid:=a[(l+r) div 2];
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if i<j then
            begin
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                calc(i,j);
            end
        else if (i=j) then calc(i,j);
    until i>j;
    if l<=j then quicksort(l,j);
    if i<=r then quicksort(i,r);
end;
begin
    readln(n);
    for i:=1 to n do
        begin
            read(a[i]);
            b[i]:=0;
        end;
    for i:=n+1 to 2*n do
        begin
            read(a[i]);
            b[i]:=1;
        end;
    n:=2*n;
    dem:=0;
    quicksort(1,n);
    for i:=1 to n do dd[i]:=false;
    for i:=1 to n-1 do
        if not dd[i] then
            if b[i]<>b[i+1] then
                begin
                    inc(dem);
                    dd[i]:=true;
                    dd[i+1]:=true;
                end;
    writeln(dem);
end.
