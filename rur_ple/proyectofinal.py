import random
jugador1 = 0
jugador2 = 0
ops = ""
gan = ""
r1 = UsedRobot(colour="green")
def ganador():
    global jugador1,jugador2,gan
    if jugador1>jugador2:
        gan = "Jugador 1 con "+repr(jugador1)+" puntos"
    else:
        gan = "Jugador 2 con "+repr(jugador2)+" puntos"
def calcularOperacion(msg):
    global ops
    op = random.randint(1,4)
    num1 = random.randint(1,10); num2 = random.randint(1,10)
    if op == 1:
        resultado = input_int(msg+repr(num1)+"+"+repr(num2))
        if resultado == (num1+num2):
            ops = "Éxito"
        else:
            ops = ""
    elif op == 2:
        resultado = input_int(msg+repr(num1)+"-"+repr(num2))
        if resultado == (num1-num2):
            ops = "Éxito"
        else:
            ops = ""
    elif op == 3:
        resultado = input_int(msg+repr(num1)+"*"+repr(num2))
        if resultado == (num1*num2):
            ops = "Éxito"
        else:
            ops = ""
    else:
        resultado = input_int(msg+repr(num1)+"//"+repr(num2))
        if resultado == (num1//num2):
            ops = "Éxito"
        else:
            ops = ""

def playJugador1():
    global jugador1
    mov = random.randint(1,6)
    for i in range(0,mov):
        if front_is_clear():
            move()
        else:
            turn_left()
            move()
    while on_beeper():
        pick_beeper()
        jugador1+=1

def playJugador2():
    global jugador2
    mov = random.randint(1,6)
    for i in range(0,mov):
        if r1.front_is_clear():
            r1.move()
        else:
            r1.turn_left()
            r1.move()
    while r1.on_beeper():
        r1.pick_beeper()
        jugador2+=1
r1.set_delay(0)
a=input_int("Debera responder las operaciones"+
    "aritmeticas correctamente,de lo contrario se le"+
    "saltara el turno"+
    "\nEl primero en llegar a 40 puntos sera el ganador."+
    "\nDigite cualquier numero para continuar")
while jugador1 <= 40 and jugador2 <= 40:
    calcularOperacion("Jugador 1: ")
    if ops == "Éxito":
        playJugador1()
    calcularOperacion("Jugador 2: ")
    if ops == "Éxito":
        playJugador2()
ganador()
print("El ganador es: " + gan)
turn_off()