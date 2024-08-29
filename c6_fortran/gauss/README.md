# Project 1: 
## Lenin Pavón Alvarez
> *Objective.* Write a program that solves a system of equations of the form $Ax=b$ by using the Gauss-Jordan method
### Features
- The matrix and vector  of possible solutions can be entered by the user. First, the size $n$ must be entered; secondly, the matrix $A$ of size $(n,n)$ can be entered row by row; lastly, the column vector $b$ can be entered.
- The data may be entered via a file if it is written with the following format:
    - 1st line: Must be a positive integer $n$. 
    - 2nd line - $(n+1)$th line: Each line must be a row of $n$ real numbers of the matrix $A$.
    - $(n+2)$th line: Must be a row of $n$ real numbers representing the column vector $b$.
- It prints on-screen the solution, if it found one. In case no solution exists (or can be found) it will also print the error messages on-screen.
- Saves both the matrix and the vector of solutions on the `output.txt` file.

### Capacidades
- El sistema puede ser ingresado por el usuario, ingresando primero la matriz $A$, luego el vector $b$ para resolver el sistema de ecuaciones lineales.
- Se pueden ingresar los datos a través de un archivo con el sig. formato
    - 1a línea: Debe ser un entero que marca la dimensión de la matriz
    - 2a línea - $(n+1)$ línea: Deben de ser filas de $n$ entradas cada una
- Marca si la solución es posible, y en caso de que no porque no. 
- Guarda el resultado en un archivo y lo muestra en Pantalla.
