var
     a : array[1..200000] of boolean;
     n,m:longint;
  procedure eratos;

    var
       i,j : longint;

    begin
       fillchar(a,m,true);
       a[1]:=false;
       for i:=2 to m div 2 do
         if a[i] then
           for j:=2 to m div i do
             a[i*j]:=false;
       writeln;
       j:=0;
       for i:=n to m do
        begin
          if a[i] then
           begin
             write(i:7);
             inc(j);
             if (j mod 10)=0 then
              writeln;
           end;
        end;
       writeln;
    end;

  begin
     read(n,m);
     eratos;
  end.




