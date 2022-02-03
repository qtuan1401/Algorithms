var n,i,j:longint;
    s1:array[1..15] of longint;
    s:string;
begin
    readln(n);
    for i:=1 to n do
        begin
            readln(s);
            for j:=1 to length(s) do
                s1[j]:=s1[j] xor ord(s[j]);
        end;
    for i:=1 to 15 do
        begin
            if (s1[i]=0) then exit;
            write(chr(s1[i]));
        end;
end.