const fi='';
      fo='';
var f,f1:Text;n,i,a,b,c,t:longint;
begin
    assign(f,fi);
    assign(f1,fo);
    reset(f);
    rewrite(f1);
    readln(f,n);t:=0;
    for i:=1 to n-1 do
        begin
            readln(f,a,b,c);
            t:=t+c;
        end;
    writeln(f1,t mod 2);
    close(f);
    close(f1);
end. 