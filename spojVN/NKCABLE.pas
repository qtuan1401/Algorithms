var a,dp:array[0..25000] of int64;
    n,i:longint;
function min(x,y:int64):int64;
begin
    if (x>y) then exit(y)
    else exit(x);
end;
begin
    readln(n);
    for i:=1 to n-1 do readln(a[i]);
    dp[1]:=0;
    dp[2]:=a[1];
    dp[3]:=a[1]+a[2];
    for i:=4 to n do dp[i]:=min(dp[i-1],dp[i-2])+a[i-1];
    writeln(dp[n]);
end.