{$mode objfpc}
uses math;
var f:array[0..10000,0..10000] of int64;
    i,j,n,m:longint;
    s,s1:string;
begin
    readln(s);
    readln(s1);
    n:=length(s);
    m:=length(s1);
    for i:=1 to n do
        for j:=1 to m do
            if (s[i]=s1[j]) then f[i,j]:=f[i-1,j-1]+1
                else f[i,j]:=max(f[i,j-1],f[i-1,j]);
    writeln(f[n,m]);
end.