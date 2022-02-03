const maxn = 250;
      oo = 60000;
      maxq = 1000000;
type tqueue = record
                front,rear,nitem:longint;
                itemx,itemy,itemz: array[0..maxq-1] of byte;
              end;
var n,s,t:byte;
    m:word;
    g: array[1..maxn,0..maxn] of byte;
    dp: array[1..maxn,1..maxn,0..1] of word;
    queue: tqueue;
procedure initq;
begin
  with queue do
  begin
    nitem:=0;
    front:=0; 
    rear:=1;
  end;
end;
function empty:boolean;
begin
  with queue do
  empty:=(nitem=0);
end;
procedure push(x,y,z:byte);
begin
  with queue do
  begin
    front:=(front+1) mod maxq;
    inc(nitem);
    itemx[front]:=x;
    itemy[front]:=y; 
    itemz[front]:=z;
  end;
end;
procedure pop(var x,y,z:byte);
begin
  with queue do
  begin
    dec(nitem);
    x:=itemx[rear];
    y:=itemy[rear]; 
    z:=itemz[rear];
    rear:=(rear+1) mod maxq;
  end;
end;
procedure enter;
var i:word;
    u,v,j,z:byte;
begin
  readln(n,m);
  readln(s,t);
  for i:=1 to n do
  g[i,0]:=0;
  for i:=1 to m do
  begin
    readln(u,v);
    inc(g[u,0]);
    g[u,g[u,0]]:=v;
  end;
  for i:=1 to n do
  for j:=1 to n do
  for z:=0 to 1 do
  dp[i,j,z]:=oo;
  dp[s,t,1]:=0;
  initq;
  push(s,t,1);
end;
procedure bfs;
var x,y,z,i:byte;
    mind: word;
begin
  repeat
    pop(x,y,z);
    if (z=0) then
    begin
      for i:=1 to g[x,0] do
      if dp[x,y,z]+1<dp[g[x,i],y,1] then
      begin
        dp[g[x,i],y,1]:=dp[x,y,z]+1;
        push(g[x,i],y,1);
      end;
    end
    else
    begin
      for i:=1 to g[y,0] do
      if dp[x,y,z]+1<dp[x,g[y,i],0] then
      begin
        dp[x,g[y,i],0]:=dp[x,y,z]+1;
        push(x,g[y,i],0);
      end;
    end;
  until empty;
  mind:=oo;
  for i:=1 to n do
  if dp[i,i,1]<mind then mind:=dp[i,i,1];
  if mind=oo then writeln(-1) else writeln(mind div 2);
end;
begin
  enter;
  bfs;
end.