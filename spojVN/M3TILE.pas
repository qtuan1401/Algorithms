var a:array[0..30] of qword;
    i:longint;
begin
    a[0]:=1;
    a[2]:=3;
    for i:=4 to 30 do
        if (i mod 2=0) then
            a[i]:=4*a[i-2]-a[i-4];
    repeat
        readln(i);
        if (i=-1) then exit;
        writeln(a[i]);
    until false;
end.