import turtle

class Score(turtle.Turtle):

    def __init__(self):
        super().__init__()
        self.score=0
        self.color("white")
        self.ht()
        self.penup()
        self.goto(0,276)
        self.write(f"Score:{self.score}",False,"center",("Courier",15,"normal"))

    def update(self):
        self.clear()
        self.write(f"Score:{self.score}", False, "center", ("Courier", 15, "normal"))

    def increase(self):
        self.score+=1
        self.update()

    def game_over(self):
        self.goto(0,0)
        self.write("GAME OVER", False, "center", ("Courier", 20, "normal"))


