from passlib.context import CryptContext

# Initialize the context
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

def generate_password(user_id):
    # Generate a password hash (this is more for storing hashed passwords)
    password_hash = pwd_context.hash(user_id)
    return password_hash

user_id = 'cs23m509'
password_hash = generate_password(user_id)
print(f'User ID: {user_id}, Password Hash: {password_hash}')
