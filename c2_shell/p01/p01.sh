#!bin/bash
echo "*****************************************"
echo ""
echo "* Bienvenido al programa"
echo ""
echo "*****************************************"
echo ""
echo "La fecha de hoy es `date +%H/%m/%y` y son las `date +%T`"
echo ""
echo "Tu home es $HOME y tu ID de usuario es $UID"
echo ""
echo -n "Ingresa tu nombre: "
read nombre
echo ""
echo "Hola $nombre, ojalá tengas un gran día"
