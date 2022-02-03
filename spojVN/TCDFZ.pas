var a:array[1..9] of byte=(6,2,6,4,2,4,8,4,6);
    i,n,c,res:longint;
function calc(n:byte):byte;
begin
    case n of
        2:exit(6);
        4:exit(2);
        6:exit(8);
        8:exit(4);
    end;
end;
begin
    readln(n);
    res:=1;
    if (n>1) then
        repeat
            c:=n div 5;
            if (n mod 5=0) then res:=res*a[(n-1) mod 10] mod 10
            else res:=res*a[n mod 10] mod 10;
            for i:=1 to c mod 4 do res:=calc(res);
            n:=n div 5;
        until (n<=1);
    writeln(res);
end.