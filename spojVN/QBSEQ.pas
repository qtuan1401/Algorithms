uses math;
var dp:array[0..1000,0..1000] of longint;
    a:array[0..10000] of longint;
    i,j,n,k:longint;
function calc(x,y:longint):longint;
begin
    calc:=x-y;
    if (calc<0) then inc(calc,k);
end;
begin
    readln(n,k);
    for i:=1 to n do
        begin
            read(a[i]);
            a[i]:=a[i] mod k;
        end;
    for i:=1 to k do dp[0][i]:=-trunc(1e9);
    dp[0][0]:=0;
    for i:=1 to n do
        for j:=0 to k-1 do
            dp[i,j]:=max(dp[i-1,j],dp[i-1,calc(j,a[i])]+1);
    writeln(dp[n,0]);
end.