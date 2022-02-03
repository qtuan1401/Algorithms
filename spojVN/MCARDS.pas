uses math;
var a,b,c,x,dp:array[0..100000] of longint;
    free:array[0..10000] of boolean;
    n,m,i,res:longint;
procedure calc;
var z,i,l,mid,r:longint;
begin
    dp[1]:=1;z:=1;
    for i:=2 to n*m do
        begin
            l:=0;
            r:=z+1;
            while (l+1<>r) do
                begin
                    mid:=(l+r) div 2;
                    if (a[i]<=a[dp[mid]]) then r:=mid
                    else l:=mid;
                end;
            dp[l+1]:=i;
            if (l=z) then inc(z);
        end;
    res:=max(res,z);
end;
procedure init;
var i:longint;
begin
    for i:=1 to n*m do a[i]:=x[b[i]]*1000+c[i];
end;
procedure back(i:longint);
var j:longint;
begin
    for j:=1 to n do
        if (free[j]) then
            begin
                x[i]:=j;free[j]:=false;
                if (i=n) then
                    begin
                        init;
                        calc;
                    end
                else back(i+1);
                free[j]:=true;
            end;
end;
begin
    readln(n,m);
    for i:=1 to n*m do read(b[i],c[i]);
    fillchar(free,sizeof(free),true);
    res:=0;
    back(1);
    write(n*m-res);
end.