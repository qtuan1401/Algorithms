var a,b:ansistring;
    i,j,n,k:longint;
    dp:array[0..5000,0..5000] of int64;
function min(x,y:int64):int64;
begin
    if (x<y) then exit(x)
    else exit(y);
end;
begin
    readln(a);
    readln(b);
    readln(k);
    //while a[length(A)]=' ' do delete(a,length(a),1);
    //while b[length(b)]=' ' do delete(b,length(b),1);
    for i:=0 to length(a) do dp[i,0]:=i*k;
    for i:=1 to length(b) do dp[0,i]:=i*k;
    for i:=1 to length(a) do
        for j:=1 to length(b) do
             dp[i,j]:=min(min(dp[i-1,j]+k,dp[i,j-1]+k),dp[i-1,j-1]+abs(ord(a[i])-ord(b[j])));
    writeln(dp[length(a),length(b)]);
end.