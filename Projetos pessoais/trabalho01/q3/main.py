# Questão 3: Sistema de autenticação simples
# Usuários e senhas pré-definidos. Criar uma função para autenticar.
import autenticador

usuarios = {
    "admin": "1234",
    "joao": "senha123",
    "maria": "abc@2024"
}

usuario = input("Usuário: ")
senha = input("Senha: ")

if autenticador.autenticar(usuarios, usuario, senha):
    print("Autenticação bem-sucedida!")
else:
    print("Usuário ou senha incorretos.")
