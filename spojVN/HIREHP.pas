uses math;
const
        nmax    =       500010;
        vc      =       1000000000000;
var
        n,m:longint;
        res:int64;
        t,p:array[0..nmax] of longint;
        tree:Array[0..nmax] of int64;
procedure add(i:longint;x:int64);
begin
        while i<=n+1 do
          begin
            tree[i]:=min(tree[i],x);
            i:=i+(i and (-i));
          end;
end;
function query(i:longint):int64;
var x:int64;
begin
        x:=vc;
        while i>0 do
          begin
            x:=min(x,tree[i]);
            i:=i-(i and (-i));
          end;
        exit(x);
end;
procedure progress;
var i,j,u,v:longint;
begin
        read(n);
        for i:=1 to n do read(t[i],p[i]);
        for i:=1 to n+1 do tree[i]:=vc;
        add(n+1,0);
        for i:=n downto 1 do
          begin
            res:=query(t[i]+1)+p[i];
            add(i,res);
          end;
        writeln(res);
end;
begin
        assign(input,'');reset(input);
        assign(output,'');rewrite(output);
          progress;
        close(input);
        close(output);
end.