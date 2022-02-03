uses math;
const m=20122007;
var res,n:int64;
    i:longint;
function calc(n:int64):int64;
var x:int64;
begin
    if n=1 then exit(3);
    x:=calc(n div 2);
    if (n mod 2=1) then calc:=(x*x*3) mod m
    else calc:=(x*x) mod m;
end;
begin
    readln(n); res:=1;
    for i:=1 to trunc(sqrt(n)) do
        if (n mod i=0) then
        begin
            res:=(res mod m)*((calc(i)-1) mod m) mod m;
            if (n div i<>i) then res:=(res mod m)*((calc(n div i)-1) mod m) mod m;
        end;
    if n=1 then writeln(2)
    else writeln(res);
end.