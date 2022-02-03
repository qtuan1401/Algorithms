var t:int64;i,j,x,y,n,k:longint;a:array[1..1000000] of longint;
procedure quicksort(l,r:longint);
var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           quicksort(l,j);
         if i<r then
           quicksort(i,r);
      end;
begin
    readln(n,k);
    for i:=1 to n do read(a[i]);
    quicksort(2,n);
    t:=a[1];
    for i:=n downto n-k+1 do t:=t+a[i];
    for i:=n-k downto 2 do t:=t-a[i];
    writeln(t);
end.