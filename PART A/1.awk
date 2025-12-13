BEGIN {
dcount = 0;
rcount = 0;
scount = 0;
}
{
event = $1;
pkt = $5;
fnode = $3;
tnode = $4;
if(event == "d")
{
dcount++;
}
if(event == "r" && tnode == "2")
{
rcount++;
}
if(event == "+" && fnode == "0")
{
scount++;
}
}
END {
printf("The no.of packets dropped  : %d\n ",dcount);
printf("The no.of packets recieved : %d\n ",rcount);
printf("The no.of packets sent : %d\n ",scount);
}
