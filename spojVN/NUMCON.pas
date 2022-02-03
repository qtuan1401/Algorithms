var     a      : array[0..150] of string;
        i,j,n  : longint;

procedure swap(var x,y : string);
 var    tmp : string;
 begin
        tmp := x;
        x := y;
        y := tmp;
 end;

begin
        n := 0;
        repeat
                inc(n);
                readln(a[n]);
        until a[n]='';

        for i := 1 to n-1 do
               for j := i+1 to n do
                     if (a[j]+a[i]>a[i]+a[j]) then swap(a[i],a[j]);
        for i :=  1 to n do write(a[i]);
end.
