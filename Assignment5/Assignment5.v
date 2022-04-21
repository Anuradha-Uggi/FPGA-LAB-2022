module Assignment5(
input wire p,
input wire q,
input wire r,
input wire s,
output wire redled,
output wire greenled,
output wire blueled
);

reg kmap_output, nand_output;
always @(*)
begin
kmap_output = (!p&!q)|(r&!s)|(!p&s)|(q&r);
nand_output = !((!(!p&!q))&(!(p&!s))&(!(!p&s))&(!(q&r)));
if(kmap_output==nand_output)
begin
redled=1;
end
else
begin
redled=0;
end
end
endmodule
