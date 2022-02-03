const fi='';
var f:text;
    s,s1:string;
    check:boolean;
    dd:array[0..9] of boolean;
    n,k:longint;
procedure back(i:longint);
var j:longint;
begin
    if (i>n) then
        begin
            if (s<s1) then
                begin
                    check:=false;
                    writeln(s1);
                end;
        end
    else
        begin
            for j:=1 to 9 do
                if (not(dd[j])) and (check) then
                    begin
                        dd[j]:=true;
                        s1:=s1+chr(j+48);
                        back(i+1);
                        delete(s1,length(s1),1);
                        dd[j]:=false;
                    end;
        end;
end;
procedure calc(x:longint);
begin
    check:=true;
    fillchar(dd,sizeof(dd),false);
    str(k,s);
    s1:='';
    n:=x;
    while length(s)<n do s:='0'+s;
    back(1);
end;
begin
    assign(f,fi);
    reset(F);
    while not(eof(F)) do
        begin
            readln(f,k);
            case k of
                    0..9:calc(1);
                    10..98:calc(2);
                    99..987:calc(3);
                    988..9876:calc(4);
                    9877..98765:calc(5);
                    98766..987654:calc(6);
                    987655..9876543:calc(7);
                    9876544..98765432:calc(8);
                    98765433..987654320:calc(9);
                    else writeln(0);
                end;
        end;
    close(f);
end.