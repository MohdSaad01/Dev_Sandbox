from flask import Flask, render_template, request
from receive_email import receive_contact_form

app=Flask(__name__)

@app.route("/")
@app.route("/index.html")
def home_page():
    return render_template("index.html") 

@app.route("/about.html")
def about_page():
    return render_template("about.html")

@app.route("/portfolio.html")
def portfolio_page():
    return render_template("portfolio.html")

@app.route("/contact.html", methods=["GET", "POST"])
def contact_page():
    if request.method == "POST":
        receive_contact_form(
            request.form.get("name"),
            request.form.get("email"),
            request.form.get("subject"),
            request.form.get("message")
        )

    return render_template("contact.html")


if __name__=="__main__":
    app.run(debug=True)

