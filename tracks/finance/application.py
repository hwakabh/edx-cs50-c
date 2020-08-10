# Add personal touch
# - feature of updating user password
# - feature of manage password policy: Longer than 8-digits, including char/num, ...etc

import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    # display a table with all of the current user stocks
    #   the numbers of share of each
    #   the current price of each stock
    #   the total value of each holding
    # display the user's current cash balance

    """Show portfolio of stocks"""
    # return "<h1>Logged in</h1>"
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        # should display form to buy a stock
        pass
    elif request.method == "POST":
        # purchase the stock as long as the user can afford it
        pass

    """Buy shares of stock"""
    return apology("TODO")


@app.route("/history")
@login_required
def history():
    # display a table with a history of all transactions by each user

    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
# @login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")

    elif request.method == "POST":
        # TODO: validation for non-input of 'symbol' should be implemented in quote.html with JavaScript
        result = lookup(symbol=request.form.get("symbol"))
        return render_template("quoted.html", result=result)

    """Get stock quote."""
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")

    elif request.method == "POST":
        # check username/email already exists or not
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        if len(rows) >= 1:
            return apology("Username already exists")

        # Insert userdata to database
        db.execute(
            "INSERT INTO users (username, hash) VALUES (:username, :password)",
            username=request.form.get("username"),
            password=generate_password_hash(request.form.get("password"))
        )

        # add cookie
        user_id = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        session['user_id'] = user_id[0]['id']

        return redirect("/index")

    """Register user"""
    return apology("TODO")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "GET":
        # should display the form to sell a stock
        pass
    elif request.method == "POST":
        # sell the specified number of shares of stock
        # update the user's cash
        pass

    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
