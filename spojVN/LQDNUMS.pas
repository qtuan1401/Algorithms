uses math;
const fi='';
      fo='';
      md=18;
      md2=10000000000000000;
var f1,f2:text;
    vt,f:array[-1..md] of qword;
    a:array[1..md] of integer;
    fgt:array[0..md] of int64;
    free:array[1..md] of boolean;
    gt,gt2:array[0..md] of int64;
    k,ra:int64;
procedure mo;
begin
assign(f1,fi);
reset(f1);
assign(F2,fo);
rewrite(f2);
end;
 
procedure dong;
begin
close(F1);
close(f2);
end;
 
procedure sinh;
var i:longint;
begin
for i:=1 to md do
 vt[i]:=vt[i-1]*10+9;
for i:=1 to md do
 f[i]:=f[i-1]+i*(vt[i]-vt[i-1]);
gt[0]:=1;gt2[0]:=1;
for i:=1 to md do
 gt[i]:=9*gt[i-1];
for i:=1 to md do
 gt2[i]:=10*gt2[i-1];
end;
 
Function GetBit(x:longint;i:byte):byte; Begin GetBit:=(x SHR (i-1)) AND 1; End;
function calc(x:int64):int64;
var  l,r,m:longint;
begin
l:=0;
r:=18;
 repeat
  m:=(l+r) div 2;
  if vt[m]<=x then begin calc:=m; l:=m+1; end
  else r:=m-1;
 until l>r;
end;
 
function process(x:longint):longint;
var i,d:integer;
begin
i:=0;
process:=0;
repeat
inc(i);
d:=0;
while getbit(x,i)=1 do begin inc(d); inc(i); end;
if d>=1 then inc(process,d-1);
until i>=18;
end;
 
function find2(x:int64):int64;
var  kq:int64;
     s:string;
     n,i,j:longint;
begin
str(x,s);
kq:=0;
n:=length(s);
for i:=1 to n do
 val(s[i],a[i]);
kq:=kq+gt2[n-2]*(a[1]-1);
if (n>=2) and (a[1]<9) then
begin
 for i:=2 to n-1 do
   kq:=kq+gt2[n-i-1]*(a[i]);
 if a[1]+1<=a[n] then inc(kq);
end;
if a[1]=9 then
begin
 for i:=2 to n-1 do
  if i<>n-1 then
   kq:=kq+gt2[n-i-1]*(a[i])
  else kq:=kq+gt2[n-i-1]*(a[i]+1);
 if n=2 then inc(kq);
end;
for i:=2 to n-1 do
  kq:=kq+gt2[i-2]*9;
  j:=calc(x);
kq:=(f[j])+(x-vt[j])*(j+1)-kq;
exit(kq);
end;
 
function find(x:int64):int64;
var  i,j,mi,n,m,ts,t,t2,d,l,y,q,d2:longint;
     s:string;
     kq:int64;
begin
if x=0 then exit(0);
str(x,s);
kq:=0;
n:=length(s);
for i:=1 to n do
 val(s[i],a[i]);
m:=1 shl n-1;
for i:=1 to n do
begin
fillchar(free,sizeof(free),true);
free[i]:=false;
fgt[n+1]:=1;
 for j:=2 to n-i+1 do
  begin
   d2:=10;
   free[j+i-1]:=false;
   d:=a[i];
   for q:=n downto 1 do
    if free[q] then
     begin
      if ((i+j)=q) or (i-1=q) or (q=1) then fgt[q]:=fgt[q+1]*9
      else fgt[q]:=fgt[q+1]*10;
     end
    else fgt[q]:=fgt[q+1];
    for q:=1 to n do
    begin
     t:=0;
     if q=1 then t:=-1 else t:=0;
     if (free[q]=false) then
      begin
       if d2=10 then begin d:=a[q];d2:=1;if (q>1) and (a[q-1]<=a[q]-1) then dec(t);kq:=kq+(a[q]+t)*(j-1)*fgt[q+1];if (q-1>=1 ) and (a[q-1]=a[q]) then break;  continue; end;
       if d>a[q] then break;
       if (d<a[q]) and ( (i-1<=0) or (d<>a[i-1])) then begin kq:=kq+(j-1)*fgt[q+1]; break; end;
       if (d=a[q]) and (q=n) and ((i-1<=0) or (a[q]<>a[i-1])) and ((i+j>n) or (a[q]<>a[i+j])) then begin kq:=kq+(j-1)*fgt[q+1]; break; end;
      end
     else
     begin
     if q=i-1 then t2:=1 else t2:=0;
     if q=n then
      begin
                if ((i+j)=q)  and (d<=a[q]) then dec(t);
                kq:=kq+max(0,(a[q]+1+t)*(j-1)*fgt[q+1]*(d2-t2))
      end
     else
      begin
                if ((i+j)=q)  and (d<=a[q]-1) then dec(t);
                kq:=kq+max(0,(a[q]+t)*(j-1)*fgt[q+1]*(d2-t2));
      end;
     end;
     if (q=(i+j)) and (a[q]=d) then break;
    end;
  end;
end;
find:=kq+find(vt[n-1]);
end;
 
function fn(x:int64):int64;
begin
fn:=find2(x)-find(x);
end;
 
procedure solve;
var l,r,m:int64;
begin
l:=1;
r:=md2;
 repeat
  m:=(l+r) div 2;
  if fn(m)>=k then begin ra:=m; r:=m-1; end
  else l:=m+1;
 until l>r;
end;
 
procedure nhap;
var i,j:longint;
begin
sinh;
readln(f1,k);
solve;
writeln(f2,ra);
end;
BEGIN
mo;
nhap;
Dong;
END.