# Q6 - Conversor de Moedas
# Crie a função que converte reais para dólares e dólares para reais (arquivo conversor.py)
# real_para_dolar e dolar_para_real. Caso o usuário não passe o tipo (real_para_dolar ou dolar_para_real) o default deve ser real_para_dolar <- padrão

import conversor

valor = float(input("Digite o valor: "))
cotacao = float(input("Digite a cotação do dólar: "))
try:
    tipo = int(input("Digite o tipo de conversão (1 para real_para_dolar ou 2 para dolar_para_real): "))
except ValueError:
    print("Tipo inválido. Usando real_para_dolar como padrão.")
    tipo = 1

if tipo == 1:
    print(f"\n{valor:.2f} reais equivalem a {conversor.real_para_dolar(valor, cotacao):.2f} dólares.")
elif tipo == 2:
    print(f"\n{valor:.2f} dólares equivalem a {conversor.dolar_para_real(valor, cotacao):.2f} reais.")
