unsigned long int factorial (unsigned int n) {
	if ( n == 0 ) {
		return 1;
	} else {
		return (unsigned long int) n * factorial (n-1);
	}
}
