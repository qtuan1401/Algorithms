uses    math;
const  fi='';
        nmax=50000;
type    data=longint;

var
        f:text;
        T,A:array[0..nmax*4] of data;
        m,n,q:data;

procedure napdulieu(i,l,r:data);
var    mid:data;
begin
        if l=r then
                begin
                        T[i]:=a[L];
                        exit;
                end;
        mid:=(l+r) div 2;
        napdulieu(i*2,l,mid);
        napdulieu(i*2+1,mid+1,r);
        T[I]:=max(T[i*2],T[i*2+1]);
end;

function timmax(i,l,r,u,v:data):data;
var    mid,maxtrai,maxphai:data;
begin
        if (v<l) or (r<u) then
                exit(0)
        else
                if (u<=l) and (r<=v) then
                        exit(T[i])
                else
                        begin
                                mid:=(l+r) div 2;
                                maxtrai:=timmax(i*2,l,mid,u,v);
                                maxphai:=timmax(i*2+1,mid+1,r,u,v);
                                exit(max(maxtrai,maxphai));

                        end;

end;

procedure xuli;
var    i,j,u,v,k:data;
begin
        assign(f,fi); reset(f);
        readln(f,n,m);
        for i:=0 to n do
                a[i]:=0;

        for i:=1 to m do
                begin
                        readln(f,u,v,k);
                        a[u]:=a[u]+k;
                        a[v+1]:=a[v+1]-k;
                end;
        for i:=1 to n do
                a[i]:=a[i]+a[i-1];

        napdulieu(1,1,n);

        readln(f,q);
        for i:=1 to q do
                begin
                        readln(f,u,v);
                        writeln(timmax(1,1,n,u,v));
                end;
        close(f);
end;



begin
        xuli;
end.