from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)
# --- Session configuration, instead of global variable
# Disabled permanent session
app.config["SESSION_PERMANENT"] = False
# Store session on the filesystem of webserver(note that new directory created named "./APP_ROOT/flask_sessions")
app.config["SESSION_TYPE"] = "filesystem"
# Append configurations to this application
Session(app)

todos = []

@app.route("/")
def tasks():
    # For the current user, if they don't have key called `todos` inside the current user session,
    # Create new key with their session
    if "todos" not in session:
        session["todos"] = []
    # passing data stored in session key to the templates
    return render_template("tasks.html", todos=session["todos"])

# by default, Flask allows only GET
@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "GET":
        return render_template("add.html")
    else:
        # Update session data only for current user
        todo = request.form.get("task")
        session["todos"].append(todo)
        return redirect("/")

