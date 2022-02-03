program bon_sau_muoilam;
var t,a,b,x,y,z:int64;
    i: longint; 
begin
        readln(t);
        for i:=1 to t do
        begin
                readln(a,b);
                x:=(b div 12) - ((a-1) div 12);
                y:=(b div 30) - ((a-1) div 30);
                z:=(b div 60) - ((a-1) div 60);
                writeln(x+y-2*z);
        end;
end.
