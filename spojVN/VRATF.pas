const fi='';
      fo='';
var d,n,m,k:longint;f,f1:text;
procedure xuli(x:longint);
begin
    if (x-k>0) and ((x-k) mod 2=0) and ((x+k) mod 2=0) then
        begin
            d:=d+1;
            xuli((x-k) div 2);
            xuli((x+k) div 2);
        end;
end;
begin
    assign(f,fi);
    assign(f1,fo);
    reset(f);
    rewrite(f1);
    readln(f,n,k);d:=1;
    xuli(n);
    writeln(f1,d);
    close(F);
    close(F1);
end.

