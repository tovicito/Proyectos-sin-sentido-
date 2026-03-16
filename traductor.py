#Python3 obviamente
import sys
CLAVE = 245
def cifrar(texto):
    traducido = "".join(chr(ord(c) ^ CLAVE) for c in texto)
    return traducido.encode().hex()
def descifrar(hex_input):
    cifrado = bytes.fromhex(hex_input).decode()
    return "".join(chr(ord(c) ^ CLAVE) for c in cifrado)
if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Uso: traductor.py [c/d] 'texto'")
        print("c = cifrar. d = descrifrar")
    else:
        modo = sys.argv[1]
        entrada = sys.argv[2]
        if modo == 'c':
            print(f"Ilegible: {cifrar(entrada)}")
        elif modo == 'd':
            print(f"Original: {descifrar(entrada)}")
        else:
            print("Elija el modo c (cifrar) o d (descifrar)")
