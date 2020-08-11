# Add personal touch
# - feature of updating user password
# - feature of manage password policy: Longer than 8-digits, including char/num, ...etc

from datetime import datetime
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
# Create tables related to each user
db.execute("CREATE TABLE IF NOT EXISTS stocks ('user_id' INTEGER, 'symbol' VARCHAR(10), 'quantity' INTEGER)")
db.execute("CREATE TABLE IF NOT EXISTS history ('timestamp' timestamp, 'user_id' INTEGER, 'transaction_type' VARCHAR(5), 'symbol' VARCHAR(5),'quantity' INTEGER, 'price' FLOAT)")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    # table data for render in index.html
    user_data = []
    user_id = session['user_id']

    # Get current user cash remained
    row = db.execute("SELECT * FROM users WHERE id = :user_id", user_id=user_id)
    cash = row[0].get("cash")

    owns = cash

    # Get list of stocks user owned & query current price
    stocks = db.execute("SELECT * FROM stocks WHERE user_id = :user_id", user_id=user_id)
    for stock in stocks:
        # Lookup latest price
        result = lookup(symbol=stock['symbol'])

        # Build dict for displaying with loop
        name = result['name']
        price = float(result.get('price', 0))
        total_per_symbol = price * float(stock['quantity'])
        user_data.append({
            'symbol': stock['symbol'],
            'name': name,
            'shares': stock['quantity'],
            'price': price,
            'total': total_per_symbol
        })

        # Calculate balance user owns
        owns += total_per_symbol

    return render_template("index.html", user_data=user_data, cash=cash, owns=owns)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")

    elif request.method == "POST":
        # TODO: Add validation case if user will submit without any input(symbol/shares)
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Check current price of provided stock
        result = lookup(symbol=symbol)
        if not result:
            return apology("Symbol not found, check company code provided.")

        # Calculate subtotal price for updating records of user
        subtotal = float(result.get('price', 0)) * float(shares)

        # Fetch current user's cash & update them
        user_id = session['user_id']
        row = db.execute("SELECT * FROM users WHERE id = :user_id", user_id=user_id)
        user_cash = float(row[0]['cash'])

        if subtotal > user_cash:
            return apology("Unsufficient cash, you could not buy stocks.")
        else:
            # Update user cash after buy stocks
            db.execute(
                "UPDATE users SET cash = :cash_remain WHERE id = :user_id",
                cash_remain=float(user_cash - subtotal),
                user_id=user_id
            )

            # Update purchase information by user
            rows = db.execute("SELECT * FROM stocks WHERE user_id = :user_id AND symbol = :symbol", user_id=user_id, symbol=symbol)
            if rows and len(rows) == 1:
                # if stock already bought, update records
                db.execute(
                    "UPDATE stocks SET symbol = :symbol, quantity = :quantity WHERE user_id = :user_id AND symbol = :symbol",
                    symbol=symbol,
                    quantity=shares+rows[0].get('quantity', 0),
                    user_id=user_id
                )
            else:
                # case if user newly buy the stock
                db.execute(
                    "INSERT INTO stocks (user_id, symbol, quantity) VALUES (:user_id, :symbol, :quantity)",
                    user_id=user_id,
                    symbol=symbol,
                    quantity=shares
                )

            # Update user history
            db.execute(
                "INSERT INTO history (timestamp, user_id, transaction_type, symbol, quantity, price) VALUES (:timestamp, :user_id, :transaction_type, :symbol, :quantity, :price)",
                timestamp=datetime.now(),
                user_id=user_id,
                transaction_type="buy",
                symbol=result.get('symbol'),
                quantity=shares,
                price=result.get('price')
            )

            return redirect("/")


@app.route("/history")
@login_required
def history():
    # display a table with a history of all transactions by each user
    user_id = session['user_id']
    transactions = db.execute("SELECT * FROM history WHERE user_id = :user_id", user_id=user_id)

    if len(transactions) <= 0:
        return apology("No transaction exists.")
    else:
        # Build body to render
        histories = []

        for transaction in transactions:
            shares = transaction['quantity']
            if transaction['transaction_type'] == 'sell':
                shares = (-1) * shares

            histories.append({
                'symbol': transaction['symbol'],
                'shares': shares,
                'price': transaction['price'],
                'timestamp': transaction['timestamp']
            })
        
        return render_template("history.html", histories=histories)


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


@app.route("/profile", methods=["GET", "POST"])
@login_required
def profile():
    user_id = session['user_id']
    user_profile = db.execute("SELECT * FROM users WHERE id = :user_id", user_id=user_id)[0]

    if request.method == "GET":
        return render_template("profile.html", account=user_profile)

    elif request.method == "POST":
        new_username = request.form.get("username")

        # Case if user did not update their username, apply current one
        if new_username == '':
            new_username = user_profile['username']
        else:
            # Case if username already taken
            rows = db.execute("SELECT * FROM users WHERE username = :username", username=new_username)
            if len(rows):
                return apology("Provided username already taken.")

        new_password = request.form.get("confirmation")
        print(new_password)
        print(generate_password_hash(new_password))
        print(user_profile['hash'])

        # Case if user would provide same password as current one
        if generate_password_hash(new_password) == user_profile['hash']:
            return apology("New password should not be same as old one.")

        else:
            db.execute(
                "UPDATE users SET username = :username, hash = :new_password WHERE id = :user_id",
                username=new_username,
                new_password=generate_password_hash(new_password),
                user_id=user_id
            )
            return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")

    elif request.method == "POST":
        # TODO: validation for non-input of 'symbol' should be implemented in quote.html with JavaScript
        result = lookup(symbol=request.form.get("symbol"))

        # Case lookup returns None
        if not result:
            return apology("Sorry, symbol not found. Check company code provided.")

        return render_template("quoted.html", result=result)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")

    elif request.method == "POST":
        # TODO: added validation with JavaScript checking password and confirmation are exactly equal or not
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

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # Get user_id for fetching stock data user already bought
    user_id = session['user_id']
    user_cash = db.execute("SELECT * FROM users WHERE id = :user_id", user_id=user_id)[0]['cash']

    if request.method == "GET":
        # Generate list of symbols
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = :user_id", user_id=user_id)
        symbols = [stock['symbol'] for stock in stocks]

        return render_template("sell.html", symbols=symbols)

    elif request.method == "POST":
        # TODO: add validation for the case if user will submit without any input(symbol/shares)
        sell_quans = int(request.form.get('shares'))
        sell_stock = request.form.get('symbol')

        # Fetch numbers of stocks for selling
        row = db.execute("SELECT * FROM stocks WHERE user_id = :user_id AND symbol = :symbol", user_id=user_id, symbol=sell_stock)

        # Case if value of shares provided is bigger than current shares
        if sell_quans > row[0]['quantity']:
            return apology("Unsufficient shares for selling.")
        else:
            # Lookup latest price of stock
            price = lookup(symbol=sell_stock)['price']
            subtotal = float(price) * float(sell_quans)

            # Update stock table
            if sell_quans == row[0]['quantity']:
                # Case if shares will be 0 after selling, delete records
                db.execute(
                    "DELETE FROM stocks WHERE user_id = :user_id AND symbol = :symbol",
                    user_id=user_id,
                    symbol=sell_stock
                )
            else:
                db.execute(
                    "UPDATE stocks SET quantity = :quantity WHERE user_id = :user_id AND symbol = :symbol",
                    quantity=int(row[0]['quantity'] - sell_quans),
                    user_id=user_id,
                    symbol=sell_stock
                )
            # Update user history
            db.execute(
                "INSERT INTO history (timestamp, user_id, transaction_type, symbol, quantity, price) VALUES (:timestamp, :user_id, :transaction_type, :symbol, :quantity, :price)",
                timestamp=datetime.now(),
                user_id=user_id,
                transaction_type="sell",
                symbol=sell_stock,
                quantity=sell_quans,
                price=price
            )
            # Update user cash
            db.execute(
                "UPDATE users SET cash = :cash WHERE id = :user_id",
                cash=float(user_cash + subtotal),
                user_id=user_id
            )

            return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
