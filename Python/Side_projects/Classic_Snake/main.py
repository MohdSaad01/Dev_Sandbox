import turtle
import time
import snake
import food
import score

screen = turtle.Screen()
screen.setup(width=600, height=600)
screen.bgcolor("purple")
screen.title(" The Snake Game")
screen.tracer(0)

snake=snake.Snake()
snake.keys()
food=food.Food()
score=score.Score()

game_is_on = True
while game_is_on:
    screen.update()
    time.sleep(0.1)
    snake.move()

    if snake.snake[0].distance(food) < 15:
        food.refresh()
        snake.extend_snake()
        score.increase()

    if snake.snake[0].xcor()>280 or snake.snake[0].ycor()>290 or snake.snake[0].xcor()<-280 or snake.snake[0].ycor()<-280:
        game_is_on = False
        score.game_over()

    for new_snake in snake.snake[1:]:
        if new_snake.distance(snake.snake[0])<15:
            game_is_on = False
            score.game_over()

screen.exitonclick()