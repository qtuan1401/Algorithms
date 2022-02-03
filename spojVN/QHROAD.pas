uses math;
var dau,cuoi,p,fat,id,a,d,ans:array[1..100000] of longint;
xet,xett:array[1..100000] of boolean;
n,i,m,res,r1,r2,dem,j,q:longint;
f,g:text;
function timcha(x:longint):longint;
begin
    while fat[x]>0 do x:=fat[x];
    exit(x);
end;
procedure kethop(r1,r2:longint);
var x:longint;
begin
    x:=fat[r1]+fat[r2];
    if r1>r2 then
    begin
        fat[r1]:=r2;
        fat[r2]:=x;
    end
    else
    begin
        fat[r1]:=x;
        fat[r2]:=r1;
    end;
end;
procedure xl;
var i:longint;
begin
    for i:=1 to n do
    begin
        xet[i]:=false;
        fat[i]:=-1;
    end;
    for i:=1 to m do
    if xett[i]<> true then
    begin
        r1:=timcha(dau[i]);
        r2:=timcha(cuoi[i]);
        if r1<>r2 then
        begin
            xet[i]:=true;
            kethop(r1,r2);
        end;
    end;
    res:=0;
    for i:=1 to n do if fat[i]<0 then inc(res);
    ans[dem]:=res;
end;
procedure xl1(t:longint);
var j:longint;
begin
    dec(dem);
    begin
        r1:=timcha(dau[t]);
        r2:=timcha(cuoi[t]);
        if r1<>r2 then
        begin
        //    xet[t]:=true;
            kethop(r1,r2);
            ans[dem] := ans[dem + 1] - 1;
        end
        else ans[dem] := ans[dem + 1];
    end;
end;
begin
    assign(f,'');reset(f);
    assign(g,'');rewrite(g);
    read(f,n,m,q);
    res:=0;
    for i:=1 to m do read(f,dau[i],cuoi[i]);
    for i:=1 to q do read(f,d[i]);
    for i:=1 to q do xett[d[i]]:=true;
    dem:=q;
    xl;
    for i:=q-1 downto 1 do
    xl1(d[i + 1]);
    for i:=1 to q do
    writeln(g,ans[i]);
    close(g);
end.