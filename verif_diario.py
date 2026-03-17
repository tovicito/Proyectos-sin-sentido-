import os
def verificar():
    if os.path.exists("traductor.py"):
        return 1
    else:
        return 0
    if os.path.exists("diario.py"):
        return 1
    else:
        return 0
if __name__ == "__main__":
    verificar()
