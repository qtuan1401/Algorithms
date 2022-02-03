var dp,a:array[0..1000] of longint;
    i,n,s1,s,j:longint;
function max(x,y:int64):int64;
begin
    if (x>y) then exit(x)
    else exit(y);
end;
function min(x,y:int64):int64;
begin
    if (x>y) then exit(y)
    else exit(x);
end;
begin
    readln(n,s);
    for i:=1 to n do read(a[i]);
    s1:=low(s1);
    for i:=1 to n do s1:=max(s1,a[i]);
    dp[0]:=s div s1-1;
    s:=s mod s1+s1;
    for i:=1 to s do dp[i]:=trunc(1e9);
    for i:=1 to s do
        for j:=1 to n do
            if (a[j]<=i) then
                dp[i]:=min(dp[i],dp[i-a[j]]+1);
    writeln(dp[s]);
end.