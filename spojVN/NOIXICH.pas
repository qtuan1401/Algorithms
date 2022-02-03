var

f: text;
thoigian: word;

somatxich: integer;
matxich: array[1..20000] of integer;

procedure input;
var
i: integer;
begin
assign(f,'');
reset(f);
readln(f, somatxich);
for i:=1 to somatxich do
read(f, matxich[i]);
close(f);
end;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=matxich[(l+r) div 2];
         repeat
           while matxich[i]<x do
            inc(i);
           while x<matxich[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=matxich[i];
                matxich[i]:=matxich[j];
                matxich[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
Procedure calculate;
var
i: integer;
begin
sort(1,somatxich);
i:=1;
thoigian:=0;
while somatxich>1 do
if matxich[i]+1<somatxich then
begin
somatxich:=somatxich-matxich[i]-1;
thoigian:=thoigian+matxich[i];
i:=i+1;
end
else
begin
thoigian:=thoigian+(somatxich-1);
somatxich:=1;
end;
end;

procedure output;
begin
assign(f, '');
rewrite(f);
writeln(f, thoigian);
close(f);
end;

begin
input;
calculate;
output;
end.


