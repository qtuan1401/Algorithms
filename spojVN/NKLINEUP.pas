uses math;
var a,amax,amin:array[1..8000000] of longint;
    i,j,n,m,l,r,resmax,resmin:longint;
procedure itupdate(k,l,r,i:longint);
var mid:longint;
begin
    if (i<l) or (r<i) then exit;
    if (l=r) then
        begin
            amax[k]:=a[i];
            amin[k]:=a[i];
            exit;
        end;
    mid:=(l+r) div 2;
    itupdate(k*2,l,mid,i);
    itupdate(k*2+1,mid+1,r,i);
    amax[k]:=max(amax[k*2],amax[k*2+1]);
    amin[k]:=min(amin[k*2],amin[k*2+1]);
end;
procedure itsearch(k,l,r,i,j:longint);
var mid:longint;
begin
    if (j<l) or (i>r) then exit;
    if (i<=l) and (r<=j) then
        begin
            resmax:=max(resmax,amax[k]);
            resmin:=min(resmin,amin[k]);
            exit;
        end;
    mid:=(l+r) div 2;
    itsearch(k*2,l,mid,i,j);
    itsearch(k*2+1,mid+1,r,i,j);
end;
begin
    readln(n,m);
    for i:=1 to n do
        begin
            readln(a[i]);
            itupdate(1,1,n,i);
        end;
    for i:=1 to m do
        begin
            readln(l,r);
            resmax:=0;resmin:=trunc(1e7);
            itsearch(1,1,n,l,r);
            writeln(resmax-resmin);
        end;
end.