import traductor
import sys
from datetime import datetime
def guardar():
    if len(sys.argv) > 1:
        mensaje = "".join(sys.argv[1:])
    else:
        mensaje = input("¿Qué quieres guardar?")
    fecha = datetime.now().strftime("[%Y-%m-%d %H:%M]")
    cifrado = traductor.cifrar(mensaje)
    with open("diario.log", "a") as f:
        f.write(f"{fecha} | {cifrado}\n")
    print("Guardado y cifrado")
if __name__ == "__main__":
    guardar()
