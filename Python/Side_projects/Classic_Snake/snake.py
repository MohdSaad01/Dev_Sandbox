import turtle

direction = [(0, 0), (-20, 0), (-40, 0)]
UP=90
DOWN=270
LEFT=180
RIGHT=0

screen=turtle.Screen()


class Snake:
    def __init__(self):
        self.snake = []
        for i in direction:
            self.add_segment(i)


    def add_segment(self,i):
        new_snake = turtle.Turtle()
        new_snake.penup()
        new_snake.shape("square")
        new_snake.color("white")
        new_snake.goto(i)
        self.snake.append(new_snake)
        
    def extend_snake(self):
        self.add_segment(self.snake[-1].position())





    def up(self):
        if self.snake[0].heading() != DOWN:
            self.snake[0].setheading(UP)

    def down(self):
        if self.snake[0].heading() != UP:
            self.snake[0].setheading(DOWN)

    def left(self):
        if self.snake[0].heading() != RIGHT:
            self.snake[0].setheading(LEFT)

    def right(self):
        if self.snake[0].heading() != LEFT:
            self.snake[0].setheading(RIGHT)

    def keys(self):
        screen.listen()
        screen.onkey(self.up, "Up")
        screen.onkey(self.down, "Down")
        screen.onkey(self.left, "Left")
        screen.onkey(self.right, "Right")

    def move(self):
        for snakes_num in range(len(self.snake) - 1, 0, -1):
            x = self.snake[snakes_num - 1].xcor()
            y = self.snake[snakes_num - 1].ycor()
            self.snake[snakes_num].goto(x, y)
        self.snake[0].fd(20)


