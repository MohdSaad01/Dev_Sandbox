from tkinter import *
import pandas
import random
BACKGROUND_COLOR = "#B1DDC6"

#Words File
try:
    french=pandas.read_csv("data\\words_to_learn.csv")

except FileNotFoundError:
    french=pandas.read_csv("data\\french_words.csv")
    words=french.to_dict(orient="records")
else:
    words = french.to_dict(orient="records")

#New Word
word={}
def new_french():
    global word,flip_timer
    window.after_cancel(flip_timer)

    word = random.choice(words)
    canvas.itemconfig(old_image, image=front)
    canvas.itemconfig(Title, text="French",fill="black")
    canvas.itemconfig(french_word, text=word["French Word"], fill="black")
    flip_timer = window.after(2000, flip_card)

#Flip Card
def flip_card():
    canvas.itemconfig(old_image,image=back)
    canvas.itemconfig(Title, text="English",fill="white")
    canvas.itemconfig(french_word, text=word["English Meaning"], fill="white")

#Known Cards
def is_know():
    words.remove(word)
    data=pandas.DataFrame(words)
    data.to_csv("data\\words_to_learn.csv",index=False)
    new_french()

#Window
window=Tk()
window.title("Flashy")
window.config(bg=BACKGROUND_COLOR,padx=50,pady=50)

flip_timer = window.after(2000, flip_card)

#Canvas
canvas=Canvas(width=800,height=526,highlightthickness=0,bg=BACKGROUND_COLOR)
front=PhotoImage(file="images\\card_front.png")
back=PhotoImage(file="images\\card_back.png")
old_image=canvas.create_image(400,265,image=front)
canvas.grid(row=0,column=0,columnspan=2)

#Text
Title=canvas.create_text(400,155,text="",font=("Ariel",40,"italic"),fill="black")
french_word=canvas.create_text(400, 263, text=f"", font=("Segoe UI", 52, "bold"), fill="black")

#Buttons
known=PhotoImage(file="images\\right.png")
known_button=Button(image=known,highlightthickness=0,command=is_know)
known_button.grid(row=1,column=0)

unknown=PhotoImage(file="images\\wrong.png")
unknown_button=Button(image=unknown,highlightthickness=0,command=new_french)
unknown_button.grid(row=1,column=1)


if __name__=="__main__":
    new_french()
    window.mainloop()

