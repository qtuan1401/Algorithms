var dp:array[0..100000] of int64;
    dd:array[0..100000] of boolean;
    i,n,k:longint;
    a:int64;
begin
    read(n,k);
    for i:=1 to k do
        begin
            read(a);
            dd[a]:=true;
        end;
    dp[1]:=1;
    dp[0]:=0;
    for i:=2 to n do
        if (dd[i]) then dp[i]:=0
        else dp[i]:=(dp[i-1]+dp[i-2]) mod 14062008;
    writeln(dp[n]);
end.