var a,b:ansistring;
    c,k,n:int64;
    f:text;
function bigdiv(a:ansistring;c:longint):longint;
var carry:int64;i:longint;
begin
    carry:=0;
    for i:=1 to length(a) do
        carry:=(ord(a[i])-48+carry*10) mod c;
    exit(carry);
end;
function etf(n:longint):longint;
var res,i:longint;
begin
    res:=n;
    for i:=2 to trunc(sqrt(n)) do
        if (n mod i=0) then
            begin
                while (n mod i=0) do n:=n div i;
                dec(res,res div i);
            end;
    if (n>1)  then dec(res,res div n);
    exit(res);
end;
function calc(a,n:int64):int64;
var x:int64;
begin
    if (n=0) then exit(1);
    if (n=1) then exit(a);
    x:=calc(a,n div 2) mod c;
    if (n and 1=1) then calc:=(((x mod c)*(x mod c) mod c)*(a mod c)) mod c
    else calc:=((x mod c)*(x mod c)) mod c;
end;
begin
    assign(f,'');
    reset(f);
    readln(f,a);
    readln(f,b);
    readln(f,c);
    k:=bigdiv(a,c);
    //writeln(etf(c));
    n:=bigdiv(b,etf(c));
    writeln(calc(k,n));
    close(f);
end.