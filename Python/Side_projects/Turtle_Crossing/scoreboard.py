FONT = ("Courier", 30, "normal")

from turtle import Turtle

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.level=1
        self.penup()
        self.hideturtle()
        self.goto(-240,260)
        self.increase_level()



    def game_over(self):
        self.hideturtle()
        self.goto(0, 0)
        self.penup()
        self.write("GAME OVER", align="center", font=FONT)

    def increase_level(self):
        self.clear()
        self.write(f"Level:{self.level}", align="center", font=("Courier", 15, "normal"))
        self.level += 1


