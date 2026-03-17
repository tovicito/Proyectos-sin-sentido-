import traductor
import os
def verif():
    import verif_diario
    devuelto = verif_diario.verificar
    if devuelto == 0:
        print("El traductor.py no existe, asegurate de que está en esta carpeta")
        return
    else:
        print("Bienvenido")
def leer_todo():
    if not os.path.exists("diario.log"):
        print("El diario no existe todavía, escribe algo con 'diario.py 'mensaje")
        return
    print("------------Leyendo archivos secretos--------------------")
    with open("diario.log", "r") as f:
        for linea in f:
            partes = linea.split(" | ")
            if len(partes) == 2:
                fecha = partes[0]
                secreto_hex = partes[1].strip()
                mensaje = traductor.descifrar(secreto_hex)
                print(f"{fecha} -> {mensaje}")
if __name__ == "__main__":
    verif()
    leer_todo()
