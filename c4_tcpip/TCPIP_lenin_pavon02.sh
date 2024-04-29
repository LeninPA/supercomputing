#!/bin/bash
ip=`echo $1 | cut -f1 -d/`
mask=`echo $1 | cut -f2 -d/`
# Tomamos cada parte de los números
ipd[0]=`echo $ip | cut -f1 -d\.`
ipd[1]=`echo $ip | cut -f2 -d\.`
ipd[2]=`echo $ip | cut -f3 -d\.`
ipd[3]=`echo $ip | cut -f4 -d\.`
ipb=()
for i in {0..3}
do
	aux=`echo "obase=2;${ipd[i]}" | bc`
	ipb+=(`printf "%0*d\n" 8 $aux`)
	echo ${ipb[i]}
done
