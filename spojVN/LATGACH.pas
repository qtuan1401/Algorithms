var a:array[0..100] of ansistring;
    i,q,n:longint;
function sum(a,b:ansistring):ansistring;
var s,carry:byte;
    i:longint;
begin
    carry:=0;
    while (length(a)<length(b)) do a:='0'+a;
    while (length(b)<length(a)) do b:='0'+b;
    for i:=length(a) downto 1 do
        begin
            s:=ord(a[i])-48+ord(b[i])-48+carry;
            carry:=s div 10;
            s:=s mod 10;
            sum:=chr(s+48)+sum;
        end;
    if (carry>0) then sum:='1'+sum;
end;
begin
    a[1]:='1';
    a[2]:='2';
    for i:=3 to 100 do a[i]:=sum(a[i-1],a[i-2]);
    readln(q);
    for i:=1 to q do
        begin
            readln(n);
            writeln(a[n]);
        end;
end.