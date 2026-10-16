from turtle import Turtle,Screen
import pandas
turtle = Turtle()
screen = Screen()

image="Blank_States_img.gif"
screen.title("America Uncovered")
screen.addshape(image)
turtle.shape(image)

states=pandas.read_csv("50_States.csv")
location=states["state"]
list_location=location.to_list()

all_guessed=False
score=0
guessed=[]


while not all_guessed:
    user_input=screen.textinput(f"State Guessed: {score}/50","Guess the state;").title()

    if user_input=="Exit":
        missing_states=[state for state in list_location if state not in guessed]
        data=pandas.DataFrame(missing_states)
        data.to_csv("missing_states.csv")
        break

    if user_input in list_location:
        score+=1

        states_row = states[states["state"] == user_input]
        x = int(states_row["x"])
        y = int(states_row["y"])

        def onscreen():
            tom = Turtle()
            tom.hideturtle()
            tom.penup()
            tom.goto(x, y)
            tom.write(user_input)
            guessed.append(user_input)

        onscreen()

    if score==50:
        all_guessed=True
