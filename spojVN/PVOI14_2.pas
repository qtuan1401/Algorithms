uses math;
const fi='';
      fo='';
        maxn=round(1e3)+100;
        maxx=5*round(1e6)+100;
        dx:array[1..4]of longint=(-1,0,1,0);
        dy:array[1..4]of longint=(0,1,0,-1);
var a,kt:array[0..maxn,0..maxn]of longint;
    qd,qc,x,y,z:array[0..maxx] of longint;
    res,n,m,top,bot:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure nhap;
var i,j:longint;
    begin
        readln(n);
        for i:=0 to n+1 do
            for j:=0 to n+1 do
                a[i,j]:=-1;
        for i:=1 to n do
            begin
            for j:=1 to n do
                read(a[i,j]);readln;
            end;
    end;
procedure themcanh(u,v,w:longint);
    begin
        inc(top);
        x[top]:=u;
        y[top]:=v;
        z[top]:=w;
    end;
procedure push(x,y,w:longint);
    begin
        inc(top);
        qd[top]:=x;
        qc[top]:=y;
        kt[x,y]:=w;
    end;
procedure bfs(x,y,w:longint);
var u,v,k:longint;
    begin
        bot:=1;
        top:=0;
        push(x,y,w);
        repeat
            x:=qd[bot];
            y:=qc[bot];
            inc(bot);
            for k:=1 to 4 do
                begin
                    u:=x+dx[k];
                    v:=y+dy[k];
                    if (a[u,v]=-1) then continue;
                    if (kt[u,v]<>w) and (abs(a[u,v]-a[x,y])=w) then
                        push(u,v,w);
                end;
        until bot>top;
    end;
procedure xulitrongso;
var i,j,xx,yy,k:longint;
    begin
        for i:=1 to n do
            for j:=1 to n do
                for k:=1 to 4 do
                    begin
                        xx:=i+dx[k];
                        yy:=j+dy[k];
                        if (a[xx,yy]<>-1) then
                            themcanh(xx,yy,abs(a[i,j]-a[xx,yy]));
                    end;
        m:=top;
        for i:=1 to n do
            for j:=1 to n do kt[i,j]:=-1;
    end;
procedure xuli;
var i,j,k:longint;
    begin
        xulitrongso;
        for i:=1 to m do
            if kt[x[i],y[i]]=z[i] then continue else
                begin
                    bfs(x[i],y[i],z[i]);
                    res:=max(res,top);
                    //writeln(res);
                end;
        writeln(res);
    end;
begin
    mo;
    nhap;
    xuli;
    dong;
end.