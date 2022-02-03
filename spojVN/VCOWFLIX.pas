var n,j,i:longint;
    t,m:int64;
    a,dp:array[0..1000000] of longint;
begin
    readln(m,n);
    for i:=1 to n do
        begin
            readln(a[i]);
            inc(t,a[i]);
        end;
    fillchar(dp,sizeof(dp),0);
    dp[t]:=0;dp[0]:=1;
    for i:=1 to n do
        for j:=m downto a[i] do
            if (dp[j]=0) and (dp[j-a[i]]=1) then dp[j]:=1;
    for i:=m downto 1 do
        if (dp[i]=1) then break;
    writeln(i);
end.