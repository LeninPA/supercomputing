#!bin/bash
echo "Iniciando programa 2"
echo -n "Ingrese ruta del archivo: "
read ruta
if test -e "$ruta"; then
	echo "El archivo existe"
	if test -d "$ruta"; then
		tipo="directorio"
	elif test -h "$ruta"; then
		tipo="liga simbólica"
  elif test -b "$ruta"; then	
		tipo="bloque"
	elif test -p "$ruta"; then
		tipo="tubería"
	elif test -c "$ruta"; then
		tipo="caracter"
	elif test -S "$ruta"; then
    tipo="socket"
	else
		tipo="ordinario"
	fi
	echo "El tipo de archivo es ordinario"
	leer=" no";escribir="no"; ejecutar=" no"
	if test -r "$ruta"; then
		leer=""
	fi
	if test -x "$ruta"; then
		ejecutar=""
	fi
	if test -w "$ruta"; then
		escribir=""
	fi
	echo "$ruta$leer se puede leer"
	echo "$ruta$escribir se puede escribir"
	echo "$ruta$ejecutar se puede ejecutar"
else
	echo "El archivo no existe o no se encuentra."
fi
echo "Buen día"
