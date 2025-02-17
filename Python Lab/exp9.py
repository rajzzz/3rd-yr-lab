import re

# txt = "Whatever can happen will Happen"
# x = re.search("^Whatever.*Happen$", txt)

# if x:
#     print("found!!")

def is_valid_variable(var_name):
    # Function to check if the variable name is valid
    variable_pattern = r'^[a-zA-Z_][a-zA-Z0-9_]*$'
    return re.match(variable_pattern, var_name) is not None

def is_strong(psd):
    if len(psd) < 8:
        return False
    
    # At least one uppercase letter
    if re.search(r'[A-Z]', psd) is None:
        return False
    
    # At least one lowercase letter
    if re.search(r'[a-z]', psd) is None:
        return False
    
    # At least one digit
    if re.search(r'[0-9]', psd) is None:
        return False
    
    # At least one special character
    if re.search(r'[^a-zA-Z0-9]', psd) is None:
        return False
    return True


# Sample variable names for operation
variable_names = ["valid_var", "2invalid", "_valid123", "invalid-var"]
psd = ["password", "Password", "password1", "Password1", "password1!", "Password1!"]
# Operation: Check if each variable name is valid
for name in variable_names:
    if is_valid_variable(name):
        print(f"'{name}' is a valid variable name.")
    else:
        print(f"'{name}' is not a valid variable name.")

for name in psd:
    if is_strong(name):
        print(f"'{name}' is a strong password.")
    else:
        print(f"'{name}' is not a strong password.")