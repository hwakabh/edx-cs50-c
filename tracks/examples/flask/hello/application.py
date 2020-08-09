from random import randint
from flask import Flask, render_template, request

# Create variable Representing my applications
app = Flask(__name__)

@app.route("/")
def index():
    # number = randint(0, 1)
    # with render_template() function, Flask search './templates' directory automatically
    # return  render_template("index.html", name="Emma", number=number)
    render_template("index.html")

@app.route("/hello")
def hello():
    request.args.get("name")
    if not name:
        return render_template("failure.html")
    return render_template("hello.html", name=name)

@app.route("/goodbye")
def bye():
    return "Goodbye!"
