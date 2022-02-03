var x:int64;s,s1:string;v:int64;
begin
    readln(x);
    s1:='';
    while x<>0 do
        begin
            v:=x mod 2;
            str(v,s);
            x:=x div 2;
            s1:=s+s1;
        end;
    writeln(s1);
end.
