var s,sb,se,sk:ansistring;
begin
    readln(sb);
    readln(se);sk:=sb;
    while length(sb)<>0 do
        begin
            if pos(sb,se)=1 then
                begin
                    delete(se,pos(sb,se),length(sb));
                    break;
                end;
            delete(sb,1,1);
        end;
    s:=sk+se;
    writeln(length(s));
end.

