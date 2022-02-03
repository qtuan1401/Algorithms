var n,m,i,j:integer;
    a:array[0..5000] of ansistring;
    dp:array[0..5000,0..5000] of int64;
function min(x,y:int64):int64;
begin
    if (x<y) then exit(x)
    else exit(y);
end;
begin
    readln(n,m);
    for i:=1 to n do readln(a[i]);
    for i:=1 to n do
        for j:=1 to m do
            if (a[i][j]='0') then dp[i,j]:=min(dp[i-1,j],min(dp[i,j-1],dp[i-1,j-1]))+1;
    for i:=1 to n do
        for j:=1 to m do dp[i,j]:=dp[i,j]+dp[i-1,j]+dp[i,j-1]-dp[i-1,j-1];
    writeln(dp[n,m]);
end.