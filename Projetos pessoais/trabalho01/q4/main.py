# Questão 4 - Verificador de Números Pares e Ímpares
# Crie uma função que receba um número inteiro e retorne se ele é par ou ímpar.
import parouimpar

try:
    numero = int(input("Digite um número: "))
    print(parouimpar.par_ou_impar(numero))
except ValueError:
    print("Por favor, digite um número válido.")