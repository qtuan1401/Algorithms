type vector=array[1..9] of char;
var i,n,k,dem:longint;
        x:vector;
        S:string;
        d:array['A'..'Z'] of longint;
        f,f1:text;

procedure ghinghiem(x:vector);
var i:integer;
begin
        for i:=1 to length(S) do write(f1,x[i]);
        writeln(f1);
end;

procedure xuli(i:longint);
var j:char;
begin
        for j:='A' to 'Z' do
            if d[j]>0 then
              begin
                   dec(d[j]);
                   x[i]:=j;
                   if i=length(S) then ghinghiem(x) else xuli(i+1);
                   inc(d[j]);
              end;
end;

begin
        assign(f,''); reset(F); readln(f,S); close(f);
        dem:=1; 
        for i:=1 to length(S) do dem:=dem*i;
        for i:=1 to length(S) do
                begin
                        inc(d[S[i]]);
                        dem:=dem div d[S[i]];
                end;
        assign(f1,''); rewrite(f1);
        writeln(f1,dem);
        xuli(1); close(f1);
        readln;
end.
