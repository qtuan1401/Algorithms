var calc:int64;i:longint;
    n:int64;
function ktngto(n:int64):boolean;
var i:longint;
begin
    for i:=2 to trunc(sqrt(n)) do
        if n mod i=0 then exit(false);
    exit(true);
end;
function mu(a,k:int64):int64;
var i:longint;
    res:int64;
begin
    res:=1;
    for i:=1 to k do res:=(res*a) mod 1000000000000000000;
    exit(res);
end;
begin
    readln(n);
    for i:=2 to 60 do
        begin
            calc:=round(exp(ln(n)/i));
            if (mu(calc,i)=n) and (ktngto(calc)) then
                begin
                    write(calc,' ',i);
                    exit;
                end;
        end;
    writeln('0');
end.