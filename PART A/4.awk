BEGIN {
    rtcp=0;
    rudp=0;
    dtcp=0;
    dudp=0;
    stcp=0;
    sudp=0;
}
{
    pkt=$5;
    event=$1;
    fromnode=$9;
    tonode=$10;

    if(event=="r" && pkt=="cbr" && fromnode=="1.0"){
        rudp++;
    }
    if(event=="r" && pkt=="tcp" && fromnode=="0.0"){
        rtcp++;
    }

    if(event=="d" && pkt=="cbr" && fromnode=="1.0"){
        dudp++;
    }
    if(event=="d" && pkt=="tcp" && fromnode=="0.0"){
        dtcp++;
    }

    if(event=="+" && pkt=="cbr" && fromnode=="1.0" && tonode=="3.1"){
        sudp++;
    }
    if(event=="+" && pkt=="tcp" && fromnode=="0.0" && tonode=="3.0"){
        stcp++;
    }
}
END{
    printf("\nNo of packets sent\n");
    printf("TCP: %d\tUDP: %d\n",stcp,sudp);

    printf("\nNo of packets received:\n");
    printf("TCP: %d\tUDP: %d\n",rtcp,rudp);

    printf("\nNo of packets dropped:\n");
    printf("TCP: %d\tUDP: %d\n",dtcp,dudp);
}
