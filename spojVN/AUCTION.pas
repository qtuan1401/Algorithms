var a:Array[1..1000] of longint;
    i,m,n,t:longint;max,k:int64;
procedure heapsort(r,n:longint);
var key,c:longint;
begin
    key:=a[r];
    while 2*r<=n do
        begin
            c:=2*r;
            if (c<n) and (a[c]<a[c+1]) then c:=c+1;
            if a[c]<=key then break;
            a[r]:=a[c];
            r:=c;
        end;
    a[r]:=key;
end;
begin
    readln(n,m);
    for i:=1 to m do readln(a[i]);
    for i:=m div 2 downto 1 do heapsort(i,m);
    for i:=m downto 2 do
        begin
            t:=a[i];
            a[i]:=a[1];
            a[1]:=t;
            heapsort(1,i-1);
        end;
    max:=low(max);
    if m<=n then
     begin
      for i:=1 to m do
        if max<a[i]*(m-i+1) then
            begin
                max:=a[i]*(m-i+1);
                k:=a[i];
            end;
     end
    else
     begin
       for i:=m-n+1 to m do
        if max<a[i]*(m-i+1) then
            begin
                max:=a[i]*(m-i+1);
                k:=a[i];
            end;
     end;
    writeln(k,' ',max);
end.


