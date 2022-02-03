var w,h,a,b,dp: array[1..20001] of longint;
    test,kq,v,m: integer;
procedure sort(l,r: integer);
var i,j,tmp,mid,mid1: integer;
begin
    i:=l; j:=r;
    mid:=W[(l+r) div 2];
    mid1:=H[(l+r) div 2];
    repeat
      while (W[i]<mid) or ((W[i]=mid) and (H[i]>mid1)) do inc(i);
      while (W[j]>mid) or ((W[j]=mid) and (H[j]<mid1)) do dec(j);
      if i<=j then
        begin
          tmp:=w[i];
          w[i]:=w[j];
          w[j]:=tmp;
          tmp:=h[i];
          h[i]:=h[j];
          h[j]:=tmp;
          inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;
procedure Solve;
var i,j,d,c,mid: integer;
begin
    dp[1]:=1;
    kq:=1;
    for i:=2 to m do
        begin
            d:=0;
            c:=kq+1;
            while (d+1<>c) do
                begin
                    mid:=(d+c) div 2;
                    if  (a[i]<a[dp[mid]]) then c:=mid
                    else d:=mid;
                end;
            dp[d+1]:=i;
            if (d=kq) then inc(kq);
        end;
    writeln(kq);
end;

procedure enter;
var i,j: integer;
begin
    readln(m);
    for i:=1 to m do read(W[i],H[i]);
    sort(1,M);
    for i:=m downto 1 do A[i]:=H[m-i+1];
    solve;
end;

begin
    readln(test);
    for v:=1 to test do enter;
end.
