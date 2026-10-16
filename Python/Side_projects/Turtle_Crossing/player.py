STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10

from turtle import Turtle

class Player(Turtle):
    def __init__(self):
        super().__init__()
        self.color("black")
        self.shape("turtle")
        self.setheading(90)
        self.penup()
        self.goto(STARTING_POSITION)


    def move_up(self):
        self.fd(MOVE_DISTANCE)

    def player_return(self):
        self.goto(STARTING_POSITION)
