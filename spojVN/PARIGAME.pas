const
        tfi     =       '';
        tfo     =       '';
type
        arr1    =       array[0..501,0..501] of int64;
var
        fi,fo:text;
        n,m,t,test:longint;
        res:boolean;
        kq,f1,f2,a:arr1;
        f:array[0..501,0..501] of boolean;
procedure nhap;
var i,j:longint;
begin
         read(fi,n);
         for i:=1 to n do
         for j:=1 to n do
          begin
           read(fi,a[i,j]);
           f1[i,j]:=f1[i-1,j]+a[i,j];
           f2[i,j]:=f2[i,j-1]+a[i,j];
          end;
end;
function xl(i,j:longint):boolean;
var k:longint;
begin
        if (i=0)or(j=0) then exit(false);
        if kq[i,j]=test then exit(f[i,j]);
        xl:=false;
        if f1[i,j] mod 2=0 then
         if (xl(i,j-1)=false) then xl:=true;
        if f2[i,j] mod 2=0 then
        if (xl(i-1,j)=false) then xl:=true;
        kq[i,j]:=test;
        f[i,j]:=xl;
end;
procedure xuly;
var i,j:longint;
begin
        res:=xl(n,n);
end;
procedure inkq;
var i,j:longint;
begin
        if res=true then writeln(fo,'YES')
        else writeln(fo,'NO');
end;
procedure mo;
begin
        assign(fi,tfi);reset(fi);
        assign(fo,tfo);rewrite(fo);
end;
begin
        mo;
         read(fi,t);
         for test:=1 to t do
          begin
            nhap;
            xuly;
            inkq;
          end;
        close(fi);
        close(fo);
end.