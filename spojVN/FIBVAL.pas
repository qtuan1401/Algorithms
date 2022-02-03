var a:array[0..100] of longint;
    j,x,y,u,v,k,i:longint;
begin
    readln(k);
    a[1]:=1;
    a[0]:=1;
    for i:=2 to 32 do
        a[i]:=(a[i-1]+a[i-2]) mod 7;
    for j:=1 to k do
        begin
            readln(x,y);
            if (y-x+1<32) then
                begin
                    k:=y-x;
                    x:=x mod 16;
                    if x=0 then x:=16;
                    y:=x+k;
                    k:=-1;
                    for i:=x to y-1 do
                        if (a[i]=a[i+1]) then
                            k:=2;
                    writeln(k);
                end
            else
                writeln(((y-x+1) div 16*16));
        end;
end.