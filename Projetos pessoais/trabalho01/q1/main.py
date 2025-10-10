# Questão 1 - Manipulação de listas e strings

frase = input("Digite uma frase: ")
palavra = input("Digite uma palavra para buscar: ")

frase_minuscula = frase.lower()
palavra_minuscula = palavra.lower()
palavras_frase = frase_minuscula.split()
quantidade = 0
for p in palavras_frase:
    if p == palavra_minuscula:
        quantidade += 1

# Quantidade de Palavras
print(quantidade)
