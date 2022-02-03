const
  fi='';
  fo='';
  max=1094800;
var
  f1,f2:text;
  a,F,T:array[1..max] of int64;
  n,smin,smax,sum:int64;
  i,j:longint;
function getmax(x,y:int64):int64;
begin
  if x<y then getmax:=y
  else getmax:=x;
end;
function getmin(x,y:int64):int64;
begin
  if x<y then getmin:=x
  else getmin:=y;
end;
begin
  Assign(f1,fi);reset(f1);
  Assign(f2,fo);rewrite(f2);
  readln(f1,n);
  For i:=1 to n do
    begin
      read(f1,a[i]);
      sum:=sum+a[i];
    end;
  F[1]:=a[1];T[1]:=a[1];
  smin:=a[1];smax:=a[1];
  For i:=2 to n do
    begin
      F[i]:=getmax(F[i-1]+a[i],a[i]);
      smax:=getmax(F[i],smax);
      T[i]:=getmin(T[i-1]+a[i],a[i]);
      smin:=getmin(smin,T[i]);
    end;
  if smax=sum then smax:=getmax(smax-a[1],smax-a[n]);
  if smin=sum then smin:=getmax(a[1]-smin,a[n]-smin);
  writeln(f2,getmax(sum-smin,smax));
  close(f1);
  close(f2);
  readln;
end.