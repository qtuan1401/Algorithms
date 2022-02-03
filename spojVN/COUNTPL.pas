var i,j,r,n:longint;
    dp:array[0..100000] of longint;
    check:array[0..2000,0..2000] of boolean;
    a:array[0..1000000] of ansistring;
    s:ansistring;
begin
    readln(s);
    n:=length(S);
    fillchar(check,sizeof(check),false);
    for i:=1 to n do check[i,i]:=true;
        for i:=2 to n do
            for j:=1 to i-1 do
                if s[i]<>s[j] then Check[j,i]:=false
                else if (j+1=i) or (check[j+1,i-1]) then check[j,i]:=true;
    dp[0]:=0;
    for i:=1 to n do dp[i]:=n;
    for i:=1 to n do
        for j:=1 to i do
            if (check[j,i]) and (dp[i]>dp[j-1]+1) then dp[i]:=dp[j-1]+1;
    writeln(dp[n]);
end.