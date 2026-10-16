from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

coffee_maker=CoffeeMaker()
menu=Menu()
money=MoneyMachine()

while True:
    choice=input("What would you like? (espresso/latte/cappuccino)")
    if choice=="off":
        break
    elif choice=="report":
        coffee_maker.report()
        money.report()
    else:
        drink=menu.find_drink(choice)
        if drink:
            if coffee_maker.is_resource_sufficient(drink):
                if money.make_payment(drink.cost):
                    coffee_maker.make_coffee(drink)
            else:
                print("Sorry we don't have enough resources.")
            another = input("Would you like to order another drink? (yes/no): ").lower()
            if another != "yes":
                print("Thank you for using the coffee machine. Goodbye! ☕")
                break
