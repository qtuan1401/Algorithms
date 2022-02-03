uses math;
type pair = record
	x, y: longint;
end;
var a: array[0..201] of pair;
	d: array[0..201] of longint;
	n, s, t: longint;
function kt(i, j, k: longint): boolean;
var t1, t2, t3, t4: int64;
begin
	t1 := a[i].x - a[j].x;
	t2 := a[i].y - a[j].y;
	t3 := a[j].x - a[k].x;
	t4 := a[j].y - a[k].y;
	if t1 * t4 <> t2 * t3 then
		exit(true);
	exit(false);
end;
procedure solve;
var i, j, k, u: longint;
begin
	readln(n);
	for i := 1 to n do
		readln(a[i].x, a[i].y);
	for i := 1 to n - 2 do
		for j := i + 1 to n - 1 do
			for k := j + 1 to n do
				if kt(i, j, k) then
					begin
						inc(s);
						inc(d[i]);
						inc(d[j]);
						inc(d[k]);
					end;
	u := 1;	t := d[1];
	for i := 2 to n do
	    if t > d[i] then
			begin
				t := d[i];
				u := i;
			end;
	writeln(s, #32, u);
end;
begin
    solve;
end.
