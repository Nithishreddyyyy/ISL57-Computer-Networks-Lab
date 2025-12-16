dcount=0
rcount=0
scount=0 

while read -r event time fnode tnode pkt rest; do
    if [[ "$event" == "d" ]]; then
        ((dcount++))
    fi

    if [[ "$event" == "r" && "$tnode" == "2" ]]; then
        ((rcount++))
    fi

    if [[ "$event" == "+" && "$fnode" == "0" ]]; then
        ((scount++))
    fi
done < "$1"

echo "The no.of packets dropped  : $dcount"
echo "The no.of packets received: $rcount"
echo "The no.of packets sent    : $scount"
