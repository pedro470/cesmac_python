# Q5 - Controle de Notas
# Complete a questão criando o notas.py e as funções de: média, maior e menor

import notas

def main():
    notas_aluno = []

    print("=== Controle de Notas ===")
    while True:
        entrada = input("Digite uma nota (ou 'sair' para encerrar): ")

        if entrada.lower() == "sair":
            break

        try:
            nota = float(entrada)
            if 0 <= nota <= 10:
                notas_aluno.append(nota)
            else:
                print("Digite uma nota entre 0 e 10.")
        except ValueError:
            print("Entrada inválida. Digite um número ou 'sair'.")

    if notas_aluno:
        print("\n--- Resultados ---")
        print(f"Média: {notas.media(notas_aluno):.2f}")
        print(f"Maior: {notas.maior(notas_aluno)}")
        print(f"Menor: {notas.menor(notas_aluno)}")
    else:
        print("Nenhuma nota foi informada.")


main()
