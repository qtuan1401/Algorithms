var s,s1:string;
    d,k:longint;
function find(k:longint;var s,s1:string):boolean;
var i,j,t:longint;
begin
    for j:=length(s) downto k do
        for i:=1 to length(s)-j+1 do
            begin
                t:=pos(copy(s,i,j),s1);
                if t<>0 then
                    begin
                        delete(s,i,j);
                        delete(s1,t,j);
                        exit(true);
                    end;
            end;
    exit(false);
end;
begin
    readln(k);
    readln(S);
    readln(s1);
    while find(k,s,s1) do inc(d);
    writeln(d);
    writeln(s);
    writeln(s1);
end.