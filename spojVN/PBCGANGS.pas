Const
        fi      ='';
        fo      ='';
        maxn    =1001;
        maxm    =5001;
 
Type
        Arr1    =array[1..maxn] of longint;
        Arr2    =array[1..6*maxm] of longint;
        Arr3    =array[1..maxn] of boolean;
 
Var
        n,m     :longint;
        adj,link:arr2;
        head    :arr1;
        kt      :arr1;
        free    :Arr3;
        kq      :longint;
        dm      :longint;
        f       :text;
 
Procedure AE(u,v:longint);
begin
        inc(dm);
        adj[dm]:=v;
        link[dm]:=head[u];
        head[u]:=dm;
end;
 
Procedure Nhap;
var
        i,u,v   :longint;
        c,k     :char;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
          begin
            kt[i]:=0;
            head[i]:=0;
            free[i]:=true;
          end;
        dm:=0;
        readln(f,m);
        for i:=1 to m do
          begin
            readln(f,c,u,v);
            if c='E' then
              begin
                if kt[u]=0 then kt[u]:=v
                  else
                    begin
                      ae(v,kt[u]);
                      ae(kt[u],v);
                    end;
                if kt[v]=0 then kt[v]:=u
                  else
                    begin
                      ae(u,kt[v]);
                      ae(kt[v],u);
                    end;
              end
            else
              begin
                ae(u,v);
                ae(v,u);
              end;
          end;
        close(f);
end;
 
Procedure DFS(u:longint);
var
        i,v     :longint;
begin
        free[u]:=false;
        i:=Head[u];
        while i<>0 do
          begin
            v:=adj[i];
            if free[v] then DFS(v);
            i:=link[i];
          end;
end;
 
Procedure Sol;
var
        u       :longint;
begin
        kq:=0;
        for u:=1 to n do
         if free[u] then
           begin
             inc(kq);
             DFS(u);
           end;
end;
 
Procedure Xuat;
begin
        assign(f,fo);
        rewrite(f);
        write(f,kq);
        close(f);
end;
 
begin
        Nhap;
        Sol;
        Xuat;
end.