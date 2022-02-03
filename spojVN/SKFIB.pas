uses math;
var pos:array[-2000001..2000001] of longint;
    a:array[0..3001] of longint;
    dp:array[0..3001,0..3001] of longint;
    t,n,i,j,res:longint;
begin
    readln(t);
    while (t>0) do
        begin
            readln(n);
            for i:=1 to n do read(a[i]);
            for i:=1 to n-1 do
                for j:=i+1 to n do dp[i,j]:=2;
            res:=0;
            for i:=1 to n-1 do
                begin
                    for j:=i+1 to n do
                        begin
                            dp[i,j]:=max(dp[i,j],dp[pos[a[j]-a[i]],i]+1);
                            res:=max(res,dp[i,j]);
                        end;
                    pos[a[i]]:=i;
                end;
            for i:=1 to n do pos[a[i]]:=0;
            writeln(res);
            dec(t);
        end;
end.