var q:byte;
    i,j,k,n:byte;
    dp:array[0..100,0..100] of qword;
begin
    dp[0,0]:=1;
    for i:=1 to 25 do
        for j:=1 to i do
            dp[i,j]:=dp[i-1,j-1]+dp[i-1,j]*j;
    readln(q);
    while (q>0) do
        begin
            readln(n,k);
            writeln(dp[n,k]);
            dec(q);
        end;
end.