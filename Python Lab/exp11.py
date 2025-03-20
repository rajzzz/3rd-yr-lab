import tkinter as tk
from tkinter import messagebox

def on_click(button_text):
    """Handles button clicks for the calculator."""
    current_text = entry_var.get()
    
    if button_text == "=":
        try:
            # Evaluate expression safely
            result = eval(current_text, {"__builtins__": None}, {})
            entry_var.set(result)
        except ZeroDivisionError:
            messagebox.showerror("Error", "Division by zero is not allowed")
            entry_var.set("")
        except Exception:
            messagebox.showerror("Error", "Invalid Expression")
            entry_var.set("")
    elif button_text == "C":
        entry_var.set("")
    else:
        entry_var.set(current_text + button_text)

# Create main window
root = tk.Tk()
root.title("Simple Calculator")
root.geometry("300x400")
root.resizable(False, False)  # Prevent resizing

# Entry widget for displaying the input and result
entry_var = tk.StringVar()
entry = tk.Entry(root, textvariable=entry_var, font=("Arial", 20), bd=5, justify="right")
entry.grid(row=0, column=0, columnspan=4, pady=10, padx=10, sticky="nsew")
entry.focus()  # Focus on entry widget

# Button layout
buttons = [
    ("7", "8", "9", "/"),
    ("4", "5", "6", "*"),
    ("1", "2", "3", "-"),
    ("C", "0", "=", "+")
]

# Create and arrange buttons using grid
for i, row in enumerate(buttons, start=1):
    for j, btn_text in enumerate(row):
        button = tk.Button(root, text=btn_text, font=("Arial", 18), width=5, height=2,
                           command=lambda text=btn_text: on_click(text))
        button.grid(row=i, column=j, sticky="nsew", padx=2, pady=2)

# Make buttons expand properly
for i in range(5):  # 5 rows (1 for entry + 4 for buttons)
    root.grid_rowconfigure(i, weight=1)
for j in range(4):  # 4 columns
    root.grid_columnconfigure(j, weight=1)

# Run the application
root.mainloop()
