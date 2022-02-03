var res:int64;
    a,b:array[0..100000] of int64;
    i,n:longint;
procedure swap(var x,y:int64);
begin
    x:=x xor y;
    y:=x xor y;
    x:=x xor y;
end;
procedure sort(l,r:int64);
var mid,i,j:int64;
begin
    i:=l;
    j:=r;
    mid:=b[(l+r) div 2];
    repeat
        while (mid>b[i]) do inc(i);
        while (mid<b[j]) do dec(j);
        if (i<=j) then
            begin
                if (i<j) then swap(b[i],b[j]);
                inc(i);
                dec(j);
            end;
    until i>j;
    if (i<r) then sort(i,r);
    if (l<j) then sort(l,j);
end;
function min(x,y:int64):int64;
begin
    if (x<y) then exit(x)
    else exit(y);
end;
function bs(l,r:int64):int64;
var mid:int64;
begin
    bs:=high(int64);
    while (l<=r) do
        begin
            mid:=(l+r) div 2;
            if (b[mid]+a[i]=0) then exit(0);
            bs:=min(abs(b[mid]+a[i]),bs);
            if (b[mid]+a[i]<0) then l:=mid+1
            else r:=mid-1;
        end;
end;
begin
    readln(n);
    for i:=1 to n do read(A[i]);
    for i:=1 to n do read(b[i]);
    sort(1,n);
    res:=high(res);
    for i:=1 to n do res:=min(res,bs(1,n));
    writeln(res);
end.