def autenticar(usuarios, usuario, senha):
    if usuarios.get(usuario) == senha:
        return True
    return False