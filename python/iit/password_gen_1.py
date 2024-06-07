import string
import random

def generate_password(length=12):
    characters = string.ascii_letters + string.digits
    password = ''.join(random.choice(characters) for i in range(length))
    return password

user_id = 'cs23m509'
password = generate_password(12)
print(f'User ID: {user_id}, Password: {password}')
