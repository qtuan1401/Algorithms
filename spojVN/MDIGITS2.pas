var s,s1,s2:ansistring;k,n:int64;i:longword;code:integer;
begin
        readln(s1);
        val(s1,n,code);
        for i:=1 to n do
                begin
                        str(i,s2);
                        s:=s+s2;
                end;
        k:=pos(s1,s);
        writeln(k);
end.
