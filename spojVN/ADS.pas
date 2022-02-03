var dd:array[0..100000] of longint;
    i,x,y,n,m,d:longint;
function find(x:longint):longint;
begin
    while dd[x]<>x do x:=dd[x];
    exit(x);
end;
function union(x,y:longint):boolean;
begin
    x:=find(x);y:=find(y);
    if (x=y) then exit(true);
    if (x<y) then dd[y]:=x
    else dd[x]:=y;
    exit(false);
end;
begin
    readln(n,m);
    for i:=1 to n do dd[i]:=i;
    for i:=1 to m do
        begin
            readln(x,y);
            union(x,y);
        end;
    for i:=1 to n do
        if (dd[i]=i) then inc(d);
    writeln(m-n+d);
end.