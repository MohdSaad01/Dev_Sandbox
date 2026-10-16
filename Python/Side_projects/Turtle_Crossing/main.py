import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)
screen.title("Safety from the cars")


player=Player()
car=CarManager()
score= Scoreboard()


screen.listen()
screen.onkey(player.move_up, "Up")

game_is_on = True
while game_is_on:
    time.sleep(0.1)
    car.create_car()
    car.move_cars()
    screen.update()

    for i in car.all_cars:
        if player.distance(i)<20:
            game_is_on = False
            score.game_over()

    if player.ycor()>280:
        player.player_return()
        score.increase_level()
        car.increase_speed()



screen.exitonclick()
