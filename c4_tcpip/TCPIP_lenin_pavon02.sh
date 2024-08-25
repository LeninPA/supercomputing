#!/bin/bash
ip=`echo $1 | cut -f1 -d/`
mask=`echo $1 | cut -f2 -d/`
# Tomamos cada parte de la dirección IP
ipd[0]=`echo $ip | cut -f1 -d\.`
ipd[1]=`echo $ip | cut -f2 -d\.`
ipd[2]=`echo $ip | cut -f3 -d\.`
ipd[3]=`echo $ip | cut -f4 -d\.`
# Conversión de los números a binario
ipb=()
for i in {0..3}
do
	aux=`echo "obase=2;${ipd[i]}" | bc`
	ipb+=(`printf "%0*d\n" 8 $aux`)
	#echo ${ipb[i]}
done
# Creación de la máscara en binario
maskb=()
suma=0
for (( j=0; j<4  ; j++))
do
	aux=""
	for (( i=1; i<=8; i++ ))
	do
		if [[ $suma -lt $mask ]]
		then
			aux="${aux}1"
		else
			aux="${aux}0"
		fi
		suma=`expr $suma + 1`
	done
	maskb+=($aux)
done

# Impresión de la máscara
maskd=()
printf "Máscara: "
for (( i=0 ; i<3 ; i++))
do
	maskd+=(`echo "ibase=2;obase=A;${maskb[i]}"|bc`)
	printf '%d.' ${maskd[i]}
done
maskd+=(`echo "ibase=2;obase=A;${maskb[3]}"|bc`)
echo "${maskd[i]}"
# Número de hosts
mask_bits=`expr 32 - $mask`
echo "Cantidad de Hosts: `echo 2^$mask_bits-2 | bc`"
# El id de red debe de tener solamente activados
# los bits de la máscara y los de la IP dada,
# por lo que obtendremos el id de red con una
# operación AND entre la IP y la Máscara
printf "ID de Red: "
for (( i=0 ; i<3 ; i++))
do
	printf '%d.' $(( 2#${maskb[i]} & 2#${ipb[i]} ))
done
echo $(( 2#${maskb[3]} & 2#${ipb[3]} ))
# Ahora queremos que todos los bits que no estaban
# Activos en la máscara se activen mientras que los
# que estaban activos en la IP también permanezcan
# así tomaremos la disyunción entre la IP y la
# negación de la máscara
printf "Broadcast: "
broad=()
for (( i=0 ; i<3 ; i++))
do
	printf '%d.' $(( ${ipd[i]} & ${maskd[i]} | 255-${maskd[i]} ))
done
echo $(( ${ipd[i]} & ${maskd[i]} | 255-${maskd[i]} ))
