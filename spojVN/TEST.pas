var i:int64;j:longword;a:array[1..100000] of string;
begin
        repeat
                i:=i+1;
                readln(a[i]);
        until a[i]='';
        for j:=1 to i do
        begin
        if a[j]<>'42' then writeln(a[j])
        else break;
        end;
end.
