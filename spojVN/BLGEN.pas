type list=array[1..10000] of qword;
var kt:array[1.. 2154434] of boolean;
    a,b:list;
    n,i,j,m:longint;f:text;
    dp:array[0..10000,0..10000] of qword;
function max(x,y:qword):qword;
begin
    if (x>y) then exit(x)
    else exit(y);
end;
function check(n:qword):boolean;
var k:qword;
begin
    k:=trunc(sqrt(n));
    if (k*k=n) then exit(true);
    k:=round(exp(ln(n)/3));
    if (k*k*k=n) and (kt[k]) then exit(true);
    exit(false);
end;
procedure enter;
var i:qword;
begin
    n:=0;
    while not(seekeoln) do
        begin
            read(i);
            if (check(i)) then
                begin
                    inc(n);
                    a[n]:=i;
                end;
        end;
    readln;
    m:=0;
    while not SeekEoLn do
        begin
            read(i);
            if (Check(i)) then
                begin
                    inc(m);
                    b[m]:=i;
                end;
        end;
end;
begin
    assign(f,'');
    reset(f);
    fillchar(kt,sizeof(kt),true);
    kt[1]:=false;
    n:=2154434;
    for i:=2 to n div 2 do
        if (kt[i]) then
            for j:=2 to n div i do kt[i*j]:=false;
    enter;
    for i:=1 to n do
        for j:=1 to m do
            if (a[i]=b[j]) then dp[i,j]:=dp[i-1,j-1]+1
            else dp[i,j]:=max(dp[i-1,j],dp[i,j-1]);
    writeln(dp[n,m]);
    close(f);
end.