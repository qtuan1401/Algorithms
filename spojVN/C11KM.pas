uses math;
const maxn=1000;
var n,i,j,res: longint;
    f,a: array[0..maxn] of longint;
    dp: array[0..maxn,0..maxn] of longint;

begin
    readln(n);
    for i:=1 to n do
        begin
            readln(a[i]);
            if a[i]>100 then f[i]:=f[i-1]+1
            else f[i]:=f[i-1];
        end;
    for i:=1 to n do
        for j:=0 to f[i] do
            begin
                dp[i,j]:=1000000000;
                if (j<=f[i-1]) then dp[i,j]:=dp[i-1,j]+a[i];
                if (a[i]>100) and (j>0) then dp[i,j]:=min(dp[i,j],dp[i-1,j-1]+a[i]);
                if (j<f[i-1]) then dp[i,j]:=min(dp[i,j],dp[i-1,j+1]);
            end;
    res:=dp[n,0];
    for i:=1 to f[n] do res:=min(res,dp[n,i]);
    writeln(Res);
end.