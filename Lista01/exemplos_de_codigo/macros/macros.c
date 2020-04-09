#include <stdio.h>
#include <stdlib.h>

// Macros comuns (mude o valor "5" para "6" e veja o que acontece)
#define NUMERO		5

// Macros com argumentos
#define SOMA(a, b)	(a+b)

// Macros com argmentos variados
#define PRINT(...)	printf(__VA_ARGS__)

//PP_CONCAT concatena x e y, PP_CONCAT_MX eh um auxiliar para a expansao de macro, e nao deve ser usado diretamento
#define PP_CONCAT_MX(x,y) x##y
#define PP_CONCAT(x,y) PP_CONCAT_MX(x,y)

//PP_STRINGIZE transforma x em "x", PP_STRINGIZE_MX eh um auxiliar para a expansao de macro, e nao deve ser usado diretamento
#define PP_STRINGIZE_MX(x) #x
#define PP_STRINGIZE(x) PP_STRINGIZE_MX(x)

int main(){
	// Macros comuns
	printf("Meu numero eh: %d\n", NUMERO);
	
	// Macros com argumentos
	printf("Soma 1: %d\n", SOMA(5,7));
	printf("Soma 2: %lf\n", SOMA(5.4, 7.3));
	
	// Macros com argmentos variados
	PRINT("Ola mundo! %d, %d, %d...\n", 1, 2, 3);
	
	// Concatenacao e Stringficacao no Pre Processamento
	PP_CONCAT(prin, tf)(PP_STRINGIZE(Ola Mundo!\n));
	printf("Ola Mundo!\n");
	
	// Compilacao condicional
	#if(NUMERO == 6)
		printf("Esta linha so eh compilada quando NUMERO igual a 6\n");
	#endif
	
	// Redefinicao de macros
	#ifdef NUMERO
		#undef NUMERO
		#define NUMERO	6
		printf("Meu numero redefinido eh: %d\n", NUMERO);
	#endif
	
	return 0;
}